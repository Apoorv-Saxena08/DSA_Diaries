class Solution {
    class node{
        public:
        long long val;
        node* prev;
        node* next;
        node(long long v){
            val=v;
            this->next=NULL;
            this->prev=NULL;
        }
    };
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int n2=n;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]) cnt++;
        }
        if(cnt==n-1) return 0;

        // priority_queue<tuple<int,node*,node*>, ... >
        // replaced with: tuple<int,int,node*,node*>
        //                (sum, leftIndex, u, v)
        priority_queue<
            tuple<long long,int,node*,node*>,
            vector<tuple<long long,int,node*,node*>>,
            greater<tuple<long long,int,node*,node*>>
        > q;

        node* head=new node(nums[0]);
        node* prev=head;
        for(int i=1;i<n;i++){
            node * curr=new node(nums[i]);
            curr->prev=prev;
            prev->next=curr;

            // push (sum, leftIndex=i-1, u, v)
            q.push(make_tuple(nums[i] + nums[i-1], i-1, prev, curr));

            prev=prev->next;
        }

        int size=n;
        set<node*> st;

        while(!q.empty()){
            auto [x, idx, u, v] = q.top();
            q.pop();

            if(st.contains(u) || st.contains(v)) continue;

            if(v->val>=u->val) cnt--;
            if(u->prev && u->prev->val<=u->val) cnt--;
            if(v->next && v->next->val>=v->val) cnt--;

            st.insert(u);
            st.insert(v);

            node* nn=new node(x);
            node* p=u->prev;
            node* nx=v->next;

            if(p){
                p->next = nn;
                nn->prev = p;
                // push new tuple with leftIndex = old leftIndex of p
                q.push(make_tuple(x + p->val, idx-1, p, nn));
            }

            if(nx){
                nx->prev = nn;
                nn->next = nx;
                // leftIndex = idx (nn replaces u,v)
                q.push(make_tuple(x + nx->val, idx, nn, nx));
            }

            if(p && p->val<=x) cnt++;
            if(nx && nx->val>=x) cnt++;

            if(u == head) head = nn;

            size--;

            node* k=head;
            
            if(size==1 || cnt==size-1)
                return n2-size;
        }
        return n2-size;
    }
};