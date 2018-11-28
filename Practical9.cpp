#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#ifdef __linux__
#define CLRSCR "clear"
#else
#define CLRSCR "cls"
#endif

using namespace std;

class PriorityScheduler;

class process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int turnAroundTime;
    int waitingTime;
    int runTime;
    int priority;
    bool isPresentInReadyQueue;
    friend class PriorityScheduler;

  public:
    process();
    bool operator<(const process &);
    void show();
};

class PriorityScheduler
{
    queue<process> jobQueue;
    queue<process> readyQueue;
    vector<process> tasks;
    const int totalProcesses;
    int totalBurstTime;
    void sortJobs();
    void schedule();
    int calculateAverageWaitingTime();
    int calculateAverageTurnAroundTime();

  public:
    PriorityScheduler(int totalProcesses);
    void simulate();
};

int main()
{
    system(CLRSCR);
    int numOfProcesses;
    cout << "Enter number of processes to simulate: ";
    cin >> numOfProcesses;
    PriorityScheduler sched(numOfProcesses);
    sched.simulate();
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
    return 0;
}

process::process()
{
    cout << "Enter process id: ";
    cin >> processId;
    cout << "Enter arrival time: ";
    cin >> arrivalTime;
    cout << "Enter burst time: ";
    cin >> burstTime;
    cout << "Enter priority: ";
    cin >> priority;
    waitingTime = 0;
    runTime = 0;
    turnAroundTime = 0;
    isPresentInReadyQueue = false;
}

bool process::operator<(const process &p)
{
    if(this->arrivalTime==p.arrivalTime)
        return this->priority<p.priority;
    return this->arrivalTime < p.arrivalTime;
}

void process::show()
{
    cout << "pid: " << processId
         << "\t\t burst time: " << burstTime
         << "\t\t waiting time: " << waitingTime
         << "\t\t turn around time: " << turnAroundTime
         << endl;
}

PriorityScheduler::PriorityScheduler(int totalProcesses) : totalProcesses(totalProcesses)
{
    for (int i = 0; i < totalProcesses; i++)
    {
        cout << "Enter details of process " << i + 1 << endl;
        process p;
        tasks.push_back(p);
    }
    totalBurstTime = 0;
}

void PriorityScheduler::sortJobs()
{
    sort(tasks.begin(), tasks.end());
}

void PriorityScheduler::simulate()
{
    system(CLRSCR);
    sortJobs();
    for (auto iter = tasks.begin(); iter != tasks.end(); iter++)
    {
        totalBurstTime += iter->burstTime;
        jobQueue.push(*iter);
    }
    if (jobQueue.front().arrivalTime != 0)
        totalBurstTime += jobQueue.front().arrivalTime;
    for (int i = 0; i < totalBurstTime; i++)
    {
        // loading processes in ready queue
        while (!jobQueue.empty() && jobQueue.front().arrivalTime == i)
        {
            readyQueue.push(jobQueue.front());
            for(auto iter = tasks.begin();iter<=tasks.end();iter++)
            {
                if (iter->processId == jobQueue.front().processId)
                    iter->isPresentInReadyQueue=true;
            }
            jobQueue.pop();
        }
        if (readyQueue.front().runTime == readyQueue.front().burstTime)
        {
            readyQueue.pop();
            schedule();
        }
        readyQueue.front().runTime++;
        // cout<<"running "<<readyQueue.front().processId<<endl;
        for (auto iter = tasks.begin(); iter != tasks.end(); iter++)
        {
            if (iter->runTime == iter->burstTime)
                continue;
            if (iter->processId != readyQueue.front().processId)
            {
                if(iter->isPresentInReadyQueue)
                    iter->waitingTime++;
            }
            else
                iter->runTime++;
        }
    }
    for (auto iter = tasks.begin(); iter != tasks.end(); iter++)
    {
        iter->turnAroundTime = iter->waitingTime + iter->burstTime;
        iter->show();
    }
    cout << endl
         << "average waiting time: " << calculateAverageWaitingTime() << endl
         << "average turn around time: " << calculateAverageTurnAroundTime() << endl;
}

int PriorityScheduler::calculateAverageWaitingTime()
{
    int sum = 0;
    for (auto iter = tasks.begin(); iter != tasks.end(); iter++)
        sum += iter->waitingTime;
    return sum / totalProcesses;
}

int PriorityScheduler::calculateAverageTurnAroundTime()
{
    int sum = 0;
    for (auto iter = tasks.begin(); iter != tasks.end(); iter++)
        sum += iter->turnAroundTime;
    return sum / totalProcesses;
}

void PriorityScheduler::schedule()
{
    vector<process> temp;
    while (!readyQueue.empty())
    {
        temp.push_back(readyQueue.front());
        readyQueue.pop();
    }
    sort(temp.begin(), temp.end(), [](process p1, process p2) {
        return p1.priority < p2.priority;
    });
    for (auto iter = temp.begin(); iter != temp.end(); iter++)
        readyQueue.push(*iter);
}