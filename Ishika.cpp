void shopping::edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\nt\t\t Modify the Record";
    cout<<"\nt\t\t Product code";

    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nFile does not exist!";
    }
    else{
        detal.open("database1.txt,"ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product new code:";
                cin>>c;
                cout<<"\n\t\t Name of the product:";
                cin>>n;
                cout<<"\n\t\t price";
                cin>>p;
                cout<<"\n\t\t Discount";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" "<<endl;
                cout<<"\n\n\t\t Record edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not fount sorry";
        }
    }
}
