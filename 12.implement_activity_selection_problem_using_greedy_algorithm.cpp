#include <bits/stdc++.h>
using namespace std;

class Activity {
public:
    int start;
    int end;

    Activity(int s, int e) : start(s), end(e) {}
};


bool compareActivities(const Activity& a1, const Activity& a2) {
    return a1.end < a2.end;
}


vector<Activity> activity_selection(vector<Activity>& activities) {

    vector<Activity> selected_activities;

    sort(activities.begin(), activities.end(), compareActivities);

    selected_activities.push_back(activities[0]);

    int previous_activity_end = activities[0].end;

    for (int i = 1; i < activities.size(); ++i) {

        if (activities[i].start >= previous_activity_end) {

            selected_activities.push_back(activities[i]);

            previous_activity_end = activities[i].end;

        }
        
    }

    return selected_activities;
}


int main()
{
    int n;
    cin>>n;
    vector<Activity> activities;

    for (int i = 0; i < n; ++i) {
        int start, end;
        std::cin >> start >> end;
        activities.push_back(Activity(start, end));
    }

    vector<Activity> selected_act = activity_selection(activities);

    // selected Activity : - 
    
    for (const Activity& activity : selected_act) {
        cout<<"[ "<< activity.start <<" "<< activity.end <<" ]"<<endl;
    }


    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class Activity
{
public:
    int start;
    int end;
    Activity(int s, int e) : start(s), end(e){};
};

bool cmp(const Activity &a1, const Activity &a2)
{
    return a1.end < a2.end;
}

vector<Activity> activity_Selection(vector<Activity> &activities)
{

    vector<Activity> selection;
    sort(activities.begin(), activities.end(), cmp);
    selection.push_back(activities[0]);
    int selection_end = activities[0].end;
    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start >= selection_end)
        {
            selection.push_back(activities[i]);
            selection_end = activities[i].end;
        }
    }
    return selection;
}

int main()
{
    int n;
    cin >> n;
    vector<Activity> activities;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        activities.push_back(Activity(x, y));
    }

    vector<Activity> selectedActivity = activity_Selection(activities);

    for (auto x : selectedActivity)
    {
        cout << "[ " << x.start << " " << x.end << " ]" << endl;
    }

    return 0;
}
*/