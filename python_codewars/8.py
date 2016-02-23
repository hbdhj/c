def knapsack(capacity, items):
    # Be greedy!
    ret = [];
    if len(items)==1:
       ret.append(int(capacity/items[0][0]));
    else:
        items_list = [];
        counter=1
        for item in items:
            item_list=list(item);
            item_list.append(counter);
            items_list.append(item_list);
            counter+=1;
        #print(items_list);
        items_list.sort(cmp=lambda x,y:cmp(float(x[1])/x[0],float(y[1])/y[0]));
        items_list.reverse();
        #print(items_list);
        cap = capacity;
        res_list=[];
        for item in items_list:
            #print(item);
            res=[];
            res.append(item[2]);
            res.append(int(cap/item[0]));
            res_list.append(res);
            cap-=int(cap/item[0])*item[0];
            #print(cap);
        res_list.sort(cmp=lambda x,y:cmp(x[0],y[0]));
        #print(res_list)
        for re in res_list:
            ret.append(re[1]);
    #print(ret);
    return ret;

knapsack(100, ((1, 1),));
knapsack(100, ((100, 1),));
knapsack(100, ((1, 1),(3, 4)));
knapsack(100, ((60, 80),(50, 50)));
knapsack(100, ((10, 10),(30, 40),(56, 78)));
knapsack(100, ((11.2,  7.4), (25.6, 17.8), (51.0, 41.2), (23.9, 15.6), (27.8, 19.0)));
