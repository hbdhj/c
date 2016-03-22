

def separate_liquids(glass):
    #your code here
    deep=len(glass);
    print("deep =",deep);
    if deep>0:
        width=len(glass[0]);
        print("width = ", width);
        if width>0:
            new={'O':0,'A':0,'W':0,'H':0};
            print(new);
            for layer in glass:
                for point in layer:
                    new[point]+=1;
            print(new)
            new2=['O']*new['O']+['A']*new['A']+['W']*new['W']+['H']*new['H'];
            #for k,n in new.iteritems():
            #    print("k=",k);
            #    if n>0:
            #        new2+=[k]*n;
            print(new2);
            new3=[]
            for i in range(0,deep):
                new3.append(new2[i*width:(i+1)*width]);
            print(new3);
            return new3;
separate_liquids([['H', 'H', 'W', 'O'],['W','W','O','W'],['H','H','O','O']]);
