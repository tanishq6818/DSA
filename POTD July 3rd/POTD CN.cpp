//BUNDLES STRING PREFIX MAX SCORE COMPARE


int groupsOfK(vector<string> &strList, int k)

{

    int n=strList.size();

    unordered_map<string,int>mp;

    for (int i = 0; i < n; i++)

    {

    for (int j = 0; j < strList[i].size(); j++)

    {

    string pref = strList[i].substr(0, j + 1);

    mp[pref]++;

    }

    }

    int res=0;

    for (unordered_map<string, int>::iterator i = mp.begin(); i != mp.end(); i++)

    {

    int count = i->second;

    res+= (count / k);

    }

    return res;

}
