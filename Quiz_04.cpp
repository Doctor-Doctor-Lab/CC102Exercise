#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int park[5][10];
    double money = 0.00;
    int choicee;

    for(int r=0;r<5;r++){
        for(int c=0;c<10;c++){
            park[r][c]=0;
        }
    }

    while(true)
    {
        cout<<"\n\n===== CAR PARKING SYSTEM ====="<<endl;
        cout<<"Total Collection: P"<<fixed<<setprecision(2)<<money<<endl<<endl;
        cout<<"1. View Parking Layout"<<endl;
        cout<<"2. Park a Car"<<endl;
        cout<<"3. Leave Parking"<<endl;
        cout<<"4. Reset Parking Area"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"================================="<<endl;
        cout<<"Enter choice: ";
        cin>>choicee;

        if(choicee==1)
        {
            cout<<endl<<"     1   2   3   4   5   6   7   8   9  10"<<endl;
            cout<<"   ------------------------------------------"<<endl;

            char letter='A';
            for(int i=0;i<5;i++)
            {
                cout<<" "<<letter<<" |";
                for(int j=0;j<10;j++)
                {
                    cout<<setw(4)<<park[i][j];
                }
                cout<<endl;
                letter = letter + 1;
            }
            cout<<endl;
        }

        else if(choicee==2)
        {
            bool full=true;
            for(int i=0;i<5;i++)for(int j=0;j<10;j++)if(park[i][j]==0)full=false;

            if(full==true){
                cout<<"Parking area is fully booked!"<<endl;
                continue;
            }

            char roww; int colm;
            cout<<"Enter row (A-E): "; cin>>roww;
            cout<<"Enter column (1-10): "; cin>>colm;

            int row_num = toupper(roww) - 'A';

            if(row_num<0 || row_num>4 || colm<1 || colm>10){
                cout<<"Invalid slot selection!"<<endl;
                continue;
            }

            colm = colm-1;

            if(park[row_num][colm]==1){
                cout<<"Slot already occupied!"<<endl;
            }
            else{
                park[row_num][colm] = 1;
                cout<<"Car successfully parked at "<<roww<<colm+1<<"!"<<endl;
            }
        }

        else if(choicee==3)
        {
            char row_leave; int col_leave;
            cout<<"Enter row (A-E): ";cin>>row_leave;
            cout<<"Enter column (1-10): ";cin>>col_leave;

            int rrr = toupper(row_leave)-'A';
            int ccc = col_leave-1;

            if(rrr<0 || rrr>4 || col_leave<1 || col_leave>10){
                cout<<"Invalid slot selection!"<<endl;
                continue;
            }

            if(park[rrr][ccc]==0){
                cout<<"Slot is already empty!"<<endl;
            }
            else{
                park[rrr][ccc]=0;
                money = money + 12.00;
                cout<<"Car at "<<row_leave<<col_leave<<" has left the parking area."<<endl;
                cout<<"Parking fee collected: P12.00"<<endl;
                cout<<"Updated Total Collection: P"<<fixed<<setprecision(2)<<money<<endl;
            }
        }

        else if(choicee==4)
        {
            for(int ii=0;ii<5;ii++){
            for(int jj=0;jj<10;jj++){
                park[ii][jj]=0;
            }}
            cout<<"Parking area reset successfully!"<<endl;
        }

        else if(choicee==5)
        {
            cout<<"Thank you for using the Car Parking System. Goodbye!"<<endl;
            break;
        }

        else
        {
            cout<<"Invalid choice! Please select 1-5."<<endl;
        }

    }

    return 0;
}
