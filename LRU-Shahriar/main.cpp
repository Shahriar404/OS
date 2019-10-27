#include <iostream>

using namespace std;

int main()
{
    int rs,ss,fault=0,flagex=0,flagex2=0,check=0;
    cout<<"RAM Size: ";
    cin>>rs;
    int ram[rs],rc[rs];
    int ck[rs]={0};
    for(int i=0;i<rs;i++){
        ram[i]=-1;
    }
    cout<<"String Size: ";
    cin>>ss;
    int str[ss];
    cout<<"Enter String Values: ";
    for(int i=0;i<ss;i++)
        cin>>str[i];


    cout<<"Output: \n";

    for(int i=0;i<ss;i++){
        for(int z=0;z<rs;z++)
            rc[z]=ram[z];

        for(int j=0;j<rs;j++){
            if(str[i]==ram[j]){
                flagex=1;
                flagex2=1;
            }
        }
        if(flagex==0){
            for(int j=0;j<rs;j++){
                if(ram[j]==-1){
                    ram[j]=str[i];
                    //fault++;
                    flagex2=1;
                    break;
                }
                else
                    flagex2=0;
            }
        }
        if(flagex2==0){
            for(int k=i-1;k>=0;k--){
                if(str[k]==ram[0]){
                    if(k>ck[0])
                        ck[0]=k;
                }
                if(str[k]==ram[1]){
                    if(k>ck[1])
                        ck[1]=k;
                }
                if(str[k]==ram[2]){
                    if(k>ck[2])
                        ck[2]=k;
                }
            }
            if(ck[0]<ck[1]&&ck[0]<ck[2]){
                ram[0]=str[i];
                //fault++;
            }
            else if(ck[1]<ck[0]&&ck[1]<ck[2]){
                ram[1]=str[i];
                //fault++;
            }
            else if(ck[2]<ck[1]&&ck[2]<ck[0]){
                ram[2]=str[i];
                //fault++;
            }
            ck[rs]={0};
        }
        flagex=0;
        flagex2=0;


        for(int z=0;z<rs;z++){
            if(rc[z]==ram[z])
                continue;
            else{
                check=1;
                break;
            }
        }
        if(check==1){
            for(int z=0;z<rs;z++)
                if(ram[z]>=0)
                    cout<<ram[z]<<" ";
            cout<<endl;
            fault++;
            check=0;
        }

    }

    cout<<"No. of Fault: "<<fault;

//    for(int i=0;i<rs;i++)
//        cout<<ram[i]<<" ";
//    for(int i=0;i<ss;i++)
//        cout<<str[i]<<" ";


    return 0;
}
