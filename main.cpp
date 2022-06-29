#include<iostream>
#include<string>
#include<list>
#include<ctime>
#include<stdlib.h>
#include<vector>
#include<fstream> 
using namespace std;
struct MSTR{
    string ad;
    int yas;
    int tel[11];
    float bakiye;
    int  iban[12];
    int kul_sifre=0;
    vector<string>durum;
    vector<int> miktar;
    vector<string>tarih;

};
list<MSTR> xx;

string time()
{

    time_t ttt;
    struct tm* tc;
    time(&ttt);
    tc= localtime(&ttt);
    return asctime(tc);

}

void MUST_KAYIT()
{
    srand(time(NULL));
    MSTR x;

    cout<<"..............MUSTERI ADI............:";cin>>x.ad;

    cout<<"..............MUSTERI YAS.....:";cin>>x.yas;
    while(x.kul_sifre<1000)
    {x.kul_sifre=rand()%10000;
    }




    x.tel[0]=0;
    x.tel[1]=5;
    for(int i=2;i<11;i++)
    {
        if(i==2)
        {
            int p=rand()%3;
            p+=3;
            x.tel[i] =p;

        }
        else
            x.tel[i]=rand()%10;
    }

    x.bakiye=500.0;
    for(int i=0;i<12;i++)
        x.iban[i]=rand()%10;
         cout<<"........... MUSTERI ADI.........:"<<x.ad;
    cout<<endl<<"...........YAS......:"<<x.yas;
    cout<<endl<<"...........SIFRE.....:"<<x.kul_sifre;
    cout<<endl<<"...........TELEFON ..........";
    for(int i=0;i<11;i++)
        cout<<x.tel[i];
    cout<<endl<<"...........BAKIYE.........:"<<x.bakiye;
    cout<<endl<<"...........IBAN.........:"<<"TR_";
    for(int i=0;i<12;i++)
        cout<<x.iban[i];


    xx.push_back(x);
    cout<<"\nISLEM BASARILI"<<endl;



}
void DEKONT(MSTR XH)
{

  string te=time();
    ofstream yazz;
    int xe=XH.miktar.size()-1;

    yazz.open("dekont.txt");
    remove("dekont.txt");
    yazz.close();
 ofstream yaz;
 yaz.open("dekont.txt");
        yaz<<"------------DEKONT BILGISI--------------"<<endl<<endl;
        yaz<<"........... MUSTERI ADI.........:"<<XH.ad<<endl;
        yaz<<"...........YAS......:"<<XH.yas<<endl;
        yaz<<"...........TELEFON ........:05";
        for(int i=0;i<5;i++)
            yaz<<"*";
    for(int i=7;i<11;i++)
        yaz<<XH.tel[i];
    yaz<<endl;
    if(xe>=0)
    yaz<<XH.miktar[xe]<<"\t"<<XH.durum[xe]<<endl;
    yaz<<"...........BAKIYE.........:"<<XH.bakiye<<endl;
    yaz<<"...........IBAN.........:"<<"TR_";
    for(int i=0;i<8;i++)
        yaz<<"*";
    for(int i=8;i<12;i++)
        yaz<<XH.iban[i];
    yaz<<endl;
yaz<<"ZAMAN......................:"<<te<<endl;






}

void BAK_SOR(string isimm,int sifre,int d){


    list<MSTR>::iterator xf=xx.begin();
    for(int i=0;i<xx.size();i++)
    {
        advance(xf,i);
        if((*xf).ad==isimm && (*xf).kul_sifre==sifre)
        {
            cout<<"\n .....ISIM.....:"<<(*xf).ad<<endl;
            cout<<"   .....BAKIYE.......:"<<(*xf).bakiye<<endl;


        }
        if(d==1)
        {

         DEKONT((*xf)) ;
        }



    }
    cout<<"------------ISLEM BASARILI----------"<<endl;
}

void PAR_CEK(string ism,int sifre,int d){


    int cpara;
    string tarihh=time();
    list<MSTR>::iterator kk=xx.begin();
    for(int i=0;i<xx.size();i++)
    {
        advance(kk,i);
        if((*kk).ad==ism&&(*kk).kul_sifre==sifre)
        {
            cout<<".....BAKIYE.............:"<<(*kk).bakiye<<endl<<endl;
            cout<<"..........CEKILMEK ISTENEN PARA..........:";cin>>cpara;
            if(cpara>(*kk).bakiye)
            {
                cout<<" .....BAKIYE YETERSIZ.........."<<endl;
                cout<<".......CEKILMEK ISTENEN PARA.......:";cin>>cpara;
            }
            (*kk).bakiye-=cpara;
            string du="CEKILDI";
            ((*kk).durum).push_back(du);
            ((*kk).miktar).push_back(cpara);
            ((*kk).tarih).push_back(tarihh);

            if(d==1)
            {

                DEKONT((*kk)) ;
            }
cout<<"\n----------------ISLEM BASARILI--------------"<<endl;



        }





    }





}

void PAR_YATIR(string isim,int sifre,int d){


    int para;

    string zamman=time();
    list<MSTR>::iterator cc=xx.begin();
    for(int i=0;i<xx.size();i++)
    {
        advance(cc,i);
        if((*cc).ad==isim&&(*cc).kul_sifre==sifre)
        {
            cout<<"YATIRMAK ISTENILEN PARA........:";cin>>para;

            (*cc).bakiye+=para;
            string du="YATIRILDI";
            ((*cc).durum).push_back(du);
            ( (*cc).miktar).push_back(para);
            ((*cc).tarih).push_back(zamman);

            if(d==1)
            {

                DEKONT((*cc)) ;
            }


        }


    }

cout<<"---------------ISLEM BASARILI------------------"<<endl;

}

void HSP_HARKET(string ism ,int sifre,int d){

    list<MSTR>::iterator kk=xx.begin();
    for(int i=0;i<xx.size();i++)
    {
        advance(kk,i);
        if((*kk).ad==ism&&(*kk).kul_sifre==sifre)
        {
            for(int i=0;i<((*kk).durum).size();i++)
            {
                cout<<(*kk).durum[i]<<"\t"<<(*kk).miktar[i]<<"\t"<<(*kk).tarih[i]<<endl;


            }
        }
    }

    if(d==1)
    {

        DEKONT((*kk)) ;
    }



}

int main()
{

    while(true)

    {
        int sec2;
        cout<<"----------ISLEMI SECIN ------------"<<endl;
        cout<<"----------*1* YONETICI------------------"<<endl;
        cout<<"-----------*2*  MUSTERI-----------------"<<endl;
        cout<<"-----------*3* CIKIS --------------------"<<endl;
        cin>>sec2;
        if(sec2<1||sec2>3)
        {
            cout<<"----------YANLIS ISLEM ! TEKRAR DENE..........:";cin>>sec2;

        }
        else if  (sec2==3) {
            break;
        }

        else  if(sec2==1)
        {
            int sifre;

            cout<<"sifre.....:"; cin>>sifre;
            if(sifre==178954)
                MUST_KAYIT();


        }
        else  if(sec2==2)
        {
        string ad;
        int sifre;
        int d;
        cout<<"MUSTERI ADI......:";cin>>ad;
        cout<<"SIFRE.............:";cin>>sifre;
        cout<<"\n DEKONT ISTIYOR MUSUNUZ ?\n 1) EVET\t 0) HAYIR   .....:";cin>>d;

        cout<<endl;
            int sec;
            while(true)
            {
                cout<<"---------YAPMAK ISTEDIGINIZ ISLEM -------------"<<endl;
                cout<<"---------*1* BAKIYE SORGULAMA ------------"<<endl;
                cout<<"---------*2*  PARA CEKME -------------"<<endl;
                cout<<"---------*3*  PARA YATIRMA -------------"<<endl;
                cout<<"---------*4*  HESAP HARAKETLERI -------------"<<endl;
                cout<<"---------*6*     ANA MENU      ------------"<<endl;
                cin>>sec;
                if(sec==6)
                    break;
                if(sec<1&&sec>6)
                {
                    cout<<"\n-----   YANLIS ISLEM\t TEKRAR  DENE  ---------\n";
                    cin>>sec;
                }
                switch(sec)
                {

                    case 1:
                        BAK_SOR(ad,sifre,d);
                        break;
                    case 2:
                        PAR_CEK(ad,sifre,d);
                        break;

                    case 3:
                        PAR_YATIR(ad,sifre,d);
                        break;
                    case 4:
                        HSP_HARKET(ad,sifre,d);
                        break;

                    default:
                        break;


                }



            }
            
        }
        
    }



}
