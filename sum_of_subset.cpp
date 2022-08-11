#include<bits/stdc++.h>
using namespace std;
int total_sum;
int sub_sum = 0;
vector<int> path;

void print_set(vector<int> &p_vector)
{
    cout<<"\{";
    for(int i=0; i<p_vector.size(); i++)
    {
        cout<<p_vector[i];
        if(i!=p_vector.size()-1)
        cout<<", ";
    }
    cout<<"\}"<<endl;
}


void sum_of_subset(vector<int> &init_set, int lev, int dest_sum, int sub_sum)
{
    if(sub_sum == dest_sum)
    {
        print_set(path);
    }
    if(lev == init_set.size()+1 || sub_sum + init_set[lev-1]  > dest_sum)
        return;
    path.push_back(lev);
    sum_of_subset(init_set, ++lev, dest_sum, sub_sum + init_set[lev-1]);
    path.pop_back();
    if(sub_sum < dest_sum)
    {
        sum_of_subset(init_set, lev++, dest_sum, sub_sum);
    }
}


int main()
{
    int sum = 30;
    vector<int> init_set = {5, 10, 12, 13, 15, 18};
    total_sum = 73;
    cout<<"Set : ";
    print_set(init_set);
    cout<<"Subsets of the elements when sum is "<<sum<<" : "<<endl;
    sum_of_subset(init_set, 1, sum, 0);
    return 0;
}
