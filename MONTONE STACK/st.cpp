ector<int> minNext(n,n);
        vector<int> minPrev(n,-1);

        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && h[st.top()] > h[i]){
                st.pop();
            }
            if(!st.empty()){
                minPrev[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(!st.empty()){
                minNext[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            int left = i - minPrev[i];
            int right = minNext[i] - i;
            // cout<<left<<" "<<right<<endl;
            ans = max(ans,(left+right-1)*h[i]);
        }

        return ans;
