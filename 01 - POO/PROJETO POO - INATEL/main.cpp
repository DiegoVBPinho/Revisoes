#include <iostream>
#include <vector>
#include <thread>
#include "Dispositivo.h"

using namespace std;

void monitorarTarefa(string ip) {
    cout << "[THREAD] Analisando trafego no IP: " << ip << endl;
}

int main() {
    cout << "--- PROJETO POO - INATEL ---\n";
    vector<thread> pool;
    vector<string> ips = {"192.168.1.1", "10.0.0.1"};

    for(auto ip : ips) pool.push_back(thread(monitorarTarefa, ip));
    for(auto &t : pool) t.join();

    cout << "Fim da execucao." << endl;
    return 0;
}