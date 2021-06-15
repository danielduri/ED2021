#include <iostream>
#include <stdexcept>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>

//DANIEL DURÁN RIVERO y JULIÁN ENCINAS FUENTES
//C37 y C38

using namespace std;
using song=string;
using artist=string;
using duration=int;

class songData{
    song Song;
    artist Artist;
    duration Duration;
    list<song>::iterator playlistLocation;
    list<song>::iterator recentLocation;


public:

    songData()= default;
    songData(song song, artist artist, duration duration) : Song(std::move(song)), Artist(std::move(artist)),
                                                                          Duration(duration) {}

    const list<song>::iterator &getPlaylistLocation() const {
        return playlistLocation;
    }

    void setPlaylistLocation(const list<song>::iterator &playlistLocation) {
        songData::playlistLocation = playlistLocation;
    }

    const list<song>::iterator &getRecentLocation() const {
        return recentLocation;
    }

    void setRecentLocation(const list<song>::iterator &recentLocation) {
        songData::recentLocation = recentLocation;
    }

    duration getDuration() const {
        return Duration;
    }
};

class iPud {
    private:
    unordered_map<song, songData> songs;
    list<song> playlist;
    list<song> recentSongs;
    duration totalPlaylist=0;

    public:
    void addSong(const song& S, const artist& A, const duration D){
        if(songs.find(S)==songs.end()){
            this->songs[S] = songData(S, A, D);
            this->songs[S].setPlaylistLocation(playlist.end());
            this->songs[S].setRecentLocation(recentSongs.end());
        }else{
            throw domain_error("addSong");
        }
    }

    void addToPlaylist(const song& S){
        if(this->songs.find(S)!=songs.end()){
            if(songs[S].getPlaylistLocation()==playlist.end()){
                this->playlist.push_front(S);
                this->songs[S].setPlaylistLocation(playlist.begin());
                this->totalPlaylist+=songs[S].getDuration();
            }
        }else{
            throw domain_error("addToPlaylist");
        }
    }

    song current(){
        if(playlist.empty()){
            throw domain_error("current");
        }
        return *playlist.rbegin();
    }

    song play(){
        if(playlist.empty()){
            cout << "No hay canciones en la lista" << endl;
            return "";
        }
        song next = *playlist.rbegin();
        this->playlist.pop_back();
        this->totalPlaylist -= songs[next].getDuration();
        this->recentSongs.push_front(next);
        this->songs[next].setPlaylistLocation(playlist.end());
        this->songs[next].setRecentLocation(recentSongs.begin());
        return next;
    }

    duration totalTime() const{
        return this->totalPlaylist;
    }

    list<song> recent(int n){
        int count = 0;
        list<song> result;

        auto it = recentSongs.rbegin();
        while(it!=recentSongs.rend() && count<n){
            result.push_front(*it);
            it++;
            count++;
        }
        return result;
    }

    void deleteSong(const song& s){
        if(songs.find(s)!=songs.end()){
            if (songs[s].getPlaylistLocation()!=playlist.end()){
                playlist.erase(songs[s].getPlaylistLocation());
                totalPlaylist-=songs[s].getDuration();
            }
            if (songs[s].getRecentLocation()!=recentSongs.end()){
                recentSongs.erase(songs[s].getRecentLocation());
            }
            songs.erase(s);
        }
    }




};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    iPud myiPud;

    while (comando != "FIN") {
        try {
            if (comando == "addSong") {
                song S;
                artist A;
                duration D;
                cin >> S >> A >> D;
                myiPud.addSong(S, A, D);
            } else if (comando == "addToPlaylist") {
                song S;
                cin >> S;
                myiPud.addToPlaylist(S);
            } else if (comando == "current") {
                myiPud.current();
            } else if (comando == "play") {
                song s = myiPud.play();
                if(!s.empty()){
                    cout << "Sonando " << s << endl;
                }
            } else if (comando == "totalTime") {
                cout << "Tiempo total " << myiPud.totalTime() << endl;
            } else if (comando == "recent") {
                int num;
                cin >> num;
                list<song> result = myiPud.recent(num);
                if(result.empty()){
                    cout << "No hay canciones recientes"<<"\n";
                }else{
                    cout << "Las "<< num << " mas recientes"<<"\n";
                    auto it = result.cbegin();
                    while(it!=result.cend()){
                        cout << "    " << *it << endl;
                        it++;
                    }
                }
            } else if (comando == "deleteSong") {
                song S;
                cin >> S;
                myiPud.deleteSong(S);
            }
        } catch (std::exception &e) {
            cout << "ERROR " << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
