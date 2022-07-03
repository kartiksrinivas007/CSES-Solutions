# Problems

## $\text{Problem 1}$

In this problem , I branch over which element I choose to use in the possible set of arrays.
and What I try to create is the sum. The property of the set which creates the sum , is that each element i s part of my 
dice - set. The question is then 
<br>

><b>The answer to the question on a higher value of the property of the set , directly depends on the anser to the question on a lower value of the property of the set and these are connected by the branch decisions.</b>

<br>

### The Question
$\text{How many such sets are there ?}$
$\text{What is the value of the Sum of all the subsets that form the sum x?}$

```C++
 cin>>n;
    vector<ll>dp(n+1);
    dp[0] = 1;
    for (int i = 1; i<=n; i++){
       for(int j =1; j<=6; j++){
        if(isgreaterthanzero(i-j)){
            dp[i] = ((dp[i]%MOD) + (dp[i-j]%MOD))%MOD;
        }
        else{
            break;
        }
       }
    }
```

The paths or branches you make are what connect the lower property value to the higher property value.
when they ask "How many such sets are there" , they are basically asking  `How many valid paths?`


## $\text{Problem 2}$

There are sets having higher property value , and there are sets having lower property value.
The sets with a higher property value map onto the sets with a lower property value, using the branches.  
Unfortunately the natural appropach of ` sum of the set ` creates branches , but disallows the question to be answered.
Counting the branches that are valid seems to depend on the structure of the previous set and not the binding property only
<br>

>The problem is that the binding property does not carry information about who exactly is contained within the set, 
in order to solve this problem , we modify our property to carry this infromation in the form of 
`sum using first i elements of the set`


<br>

### The Question
$\text{How many such Ordered sets are there ?}$

```C++
sort(currency.begin(), currency.end());
    vector<ll>dp(n+1,0);
    dp[0] =1;
    for(auto y: currency){
        for(int i=0; i<=n; i++){
            if(isgreaterthanzero(i-y)){
                dp[i] = ((dp[i]%MOD) + (dp[i-y]%MOD))%MOD;
            }
            else{
                continue;
            }
        }
    }
```

Once that information has been added, the `Question ` becomes simpler to answer, because every branch you create is now a valid path. because there is only one unique ascending order of coins.

## Problem 3

THis question is different, it does not care about the path or the number of paths it takes to get to the answer.
all it cares is about the value of the sum of pages when we reach the final property value.
So since our ` dp ` does not carry any information that is even close to this, we must provide it something that carries information as to how to maximize the number of pages. 

Here i have two property values :-
I can either choose - to use the ` max pages using first i elements `  - Branched  on `Choice of taking the i+1 book` 
Or I can choose `max pages using money x ` - branched on `Choice of spending money on the i+1 book`

> The question is about the nature of the branching, do I branch on money or do I branch on Books?

> The asnwer is we do BOTH! Because the number of pages I Buy depends on the amount OF MONEY I have !

```C++
  for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {   
            dp[i][j] = dp[i-1][j];
            if(j >= price[i-1])
            {
                dp[i][j] = max (dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]); //max of both the boxes included in dp[i][j]. 
            }
        }
    }

```

# Summary of the Main Ideas 

* Choose a Binding Property Value such that you can make connections to lower property values
* Choose all possble Branching possibilities , each one for each thing your binding property value depends on
* The Change in the `question` can change the Binding property value , the binding property value needs to carry the necessary information regarding the `Question`

<b>The Three main things are the Branches, the Question, and the Binding Property Value</b>