#include<iostream>
#include<string>
#include<Eigen/Dense>
#include<cmath>

using namespace std;
using namespace Eigen;

int mod26=26, mod27=27;

double round(double d)
{
  return floor(d + 0.5);
}

int multi_inverz(int broj, int mod)
{
    int provjera;
    for (int j=0; j<mod; j++)
    {
        provjera=j*broj;
        if (provjera%mod==1)
        return j;
    }
    return -1;
}

int pretvorba(int broj, int mod)
{
    while(broj<0)
    {
                 broj+=mod;
    }
    return broj;
}

MatrixXi modulo_inverz(MatrixXd matrica, int provjera, int n, int mod)
{
         MatrixXd pomocna(n,n);
         pomocna=(matrica.inverse())*(matrica.determinant());
         int temp;
         MatrixXi racun(n,n);
         for(int i=0; i<n; i++)
         {
                 for (int j=0; j<n; j++)
                 {
                     temp=(int)round(pomocna(i,j));
                     racun(i,j)=temp;    
                 }
         }
         MatrixXi m3(n,n);
         m3 = racun*provjera;
         int pom1,pom2,pom5;
         int pom3, pom4;
         for(int i=0; i<n; i++)
         {
                 for(int j=0; j<n; j++)
                 {
                         pom1=m3(i,j);
                         pom2=(pretvorba(pom1, mod));
                         m3(i,j)=pom2;
                 }
         }
         for(int i=0; i<n; i++)
         {
                 for(int j=0; j<n; j++)
                 {
                         pom3=m3(i,j);
                         pom4=pom3%mod;
                         m3(i,j)=pom4;
                 }
         }
return m3;         
}
/* GAUSS
MatrixXi gauss(MatrixXi matrica, MatrixXi jedinicna, int red){
         int fakt;
	for (int i=0; i<red;i++)
		for(int j=0;j<red;j++){
			int mi=multi_inverz(matrica(j,j), mod26);
			if (mi!=-1)
				for (int k=0;k<red;k++){
					matrica(j,k)=((mi*matrica(j,k))%26);
					jedinicna(j,k)=((mi*jedinicna(j,k))%26);
				}
				for (int k=0;k<red; k++)
                {
					if (k!=j)
                    {
						fakt=matrica(k,j);
					    for(int m=0; m<red; m++)
                        {
					        matrica(k,m)=(matrica(k,m)-(fakt*matrica(j,m)))%26;
							jedinicna(k,m)=(jedinicna(k,m)-(fakt*jedinicna(j,m)))%26;
                        }
                    }
                 }
			
				
			
			
		}
		int pom;
		for (int i=0; i<red; i++)
		    for (int j=0; j<red; j++)
		    {
                     pom=pretvorba(jedinicna(i,j), mod26);
                     jedinicna(i,j)=pom;
            }
		return jedinicna;
}*/

int main(){
    int izbor;
    do
    {
    cout<<"==========================IZBORNIK================================"<<endl;
    cout<<"1. Zadatak: Multiplikativni inverzi elemenata u prstenu Z26."<<endl;
    cout<<"2. Zadatak: Racunanje inverz modulo 26 matrica."<<endl;
    cout<<"3. Zadatak: Sifriranje i desifriranje pomocu Hillove 2-sifre."<<endl;
    cout<<"4. Zadatak: Sifriranje pomocu Hillove n-sifre."<<endl;
    cout<<"5. Zadatak: Desifriranje pomocu Hillove n-sifre."<<endl;
    cout<<"9. IZLAZ!"<<endl;
    cout<<"=================================================================="<<endl;
    cout<<"Vas odabir: ";
    cin>>izbor;
    
               switch (izbor)
               {
                      
                      case 1:
                      {
                           int rezultat;
                           for(int i=0; i<26; i++)
                           {
                                   rezultat=multi_inverz(i, mod26);
                                   if (rezultat!=-1)
                                   cout<<"a= "<<i<<"        "<<"a^-1= "<<rezultat<<endl;
                            }
                            break;
                      }
               
    
                      case 2:
                      {
                           int n;
                           cout<<"Unesite red matrice A: ";
                           cin>>n;
                           MatrixXd matrica(n,n);
                           MatrixXd jedinicna = MatrixXd::Identity(n,n);
                           for(int i=0; i<n; i++)
                           {
                                   for(int j=0; j<n; j++)
                                   {
                                           cout<<"Unesite a"<<i+1<<j+1<<": ";
                                           cin>>matrica(i,j);
                                   }
                           }
                           cout<<endl<<"Matrica: "<<endl<<matrica<<endl;
                           int determinanta=(int)(matrica.determinant());
                           int pret= pretvorba(determinanta, mod26);
                           int provjera = multi_inverz(pret, mod26);
                           if(provjera==-1)
                                           cout<<"Matrica nema inverz!"<<endl;
                           else
                           {
                               cout<<endl<<"Inverz modulo 26: "<<endl<<modulo_inverz(matrica, provjera, n, mod26)<<endl;
                               
                           }                           
                           break;
                      }
                      
                      
                      case 3:
                      {
                           int izborSifriranja=0, izborDesifriranja=0;
                           Matrix2i A;
                	       A << 1,2,0,5;
                	       int izbor;
                	       cout<<endl;
                	       cout<<"---------------------------------"<<endl;
                		   cout <<"Za sifriranje odabrite (1)" << endl;
                	       cout <<"Za desifriranje odabreite (2)" << endl; 
                	       cout<<"---------------------------------"<<endl;
                	       cout<<"Vas odabir: ";
                		   cin >> izbor;
                    
                
                           if (izbor == 1)
                           {
                              cout <<endl;
                    	      cout <<"Matrica pomocu koje ce sifrirat: "<<endl;
                		      cout << A << endl;
                    	      do
                		      {
                                   cout <<endl;
                		           cout <<"Koju poruku zelite sifrirati: "<<endl;
                		           cout <<"-------------------------------------------------------------------------------"<<endl;
                	               cout <<"1) Ja volim Matematiku" << endl;
                	               cout <<"2) Derivacija pretpostavlja neprekidnost, neprekidnost se bazira na necem beskonacno malom, ali nitko ne moze otkriti sto to beskonacno malo moze biti"<<endl;
                	               cout <<"-------------------------------------------------------------------------------"<<endl;
                	               cout <<"Vas odabir: ";
                	               cin >> izborSifriranja;
		                      }while (izborSifriranja != 1 && izborSifriranja != 2);
                           }
                
                
                           if (izbor == 2)
                           {
                    	      cout << "Koji sifrat zelite desifrirati:" << endl;
                    	      cout << "-------------------------------------------------------------------------------" << endl;
               	              cout << "1) jaoyjbfgxglobglobxsw" << endl;
                    	      cout << "2) lugnvasnjacvzuwvxjtaqbjazlhvzu nclxjrwvuweyxopoqcoijcwbaonrazlzwvukukwjulxnlekoqxgwblg aanzltolqzlcwnqguaqmxgninijuqkomwjulxnlekoqxgwbmwnqgubftogw" << endl;
                    	      cout << "-------------------------------------------------------------------------------"<<endl;
                    	      cout <<"Vas odabir: ";
                    	      cin >> izborDesifriranja;
                           }
                
                	       string plaintext = "";
                
                	       if (izborDesifriranja == 1 || izborSifriranja == 1)
                		      plaintext = "ja volim matematiku ";
                
                	       if (izborDesifriranja == 2 || izborSifriranja == 2)
                		      plaintext = "derivacija pretpostavlja neprekidnost neprekidnost se bazira na necem beskonacno malom, ali nitko ne moze otkriti sto to beskonacno malo moze biti ";
                
                	       int n = 0;
                	       int numberPlainText[200];
                
                           string abeceda = "abcdefghijklmnopqrstuvwxyz ";
                	       string ChiperText = "";
                	
                	       for (int i = 0; i < plaintext.length(); i++)
                	       {
                		       for (int j = 0; j < abeceda.length(); j++)
                		       {
                			       if (plaintext[i] == abeceda[j])
                				   {
                						numberPlainText[n] = j;
                						n++;				
              				       }
                			
                               }
                	
                	       }

                
                		   Vector2i jedVector, rezultat;
                		   int numberChiperText[n];
                		   int tmpBrojac = 0;
                
                		   for (int i = 0; i < n; i+=2)
                		   {
                			   jedVector << numberPlainText[i], numberPlainText[i+1];
                		       rezultat = A * jedVector ;
                
                		       for (int r = 0; r < 2; r++)
                		       {
                		    	   for (int s = 0; s < 1; s++)
                		    	   {
                		    		   int tmp,modulo;
                		    		   tmp = rezultat (r,s);
                		    		   modulo = tmp % 27;
                		    		   rezultat(r,s) = modulo;
                		    		   numberChiperText[tmpBrojac] = modulo;
                		    		   tmpBrojac++;
                		    	    }
                		        }
                		    }
                
                
                		    if (izborSifriranja == 1 || izborSifriranja == 2)
                		    {
                               cout<<"Sifrirana poruka izgleda: "<<endl;
            				   for (int i = 0; i < n; i ++)
            			       {
                				   int tmpslovo = 0;
                				   tmpslovo = numberChiperText[i];					
                				   cout << abeceda[tmpslovo];
                			    }
                			    cout<<endl;
                		     }
                		
                		
                		     if (izborDesifriranja == 1 || izborDesifriranja == 2 )
                		     {
                			    Matrix2i AInverz;
                			    AInverz << 1,5,0,11;
                
                			    Vector2i jedVectorDesifriranje, rezultatDesifiranje;
                
                			    tmpBrojac = 0;
                
                			    for (int i = 0; i < n-1; i+=2)
                			    {
                				    jedVectorDesifriranje << numberChiperText[i], numberChiperText[i+1];
                			        rezultatDesifiranje = AInverz * jedVectorDesifriranje;
                			        for (int r = 0; r < 2; r++)
                			        {
                			    	    for (int s = 0; s < 1; s++)
                			    	    {
                			    		    int tmp,modulo;
                			    		    tmp = rezultatDesifiranje (r,s);
                			    		    modulo = tmp % 27;
                			    		    rezultatDesifiranje(r,s) = modulo;
                			    		    numberPlainText[tmpBrojac] = modulo;
                			    		    tmpBrojac++;
                			    	     }
                			          }
                			     }
                			     
                                 cout<<"Ovo je desifrirana poruka: "<<endl;
                			     for (int i = 0; i < n; i ++)
                			     {
                				     int tmpslovo = 0;
                				     tmpslovo = numberPlainText[i];					
                				     cout << abeceda[tmpslovo];
                			      }
                			      cout<<endl;
                	        	}
                           
                       break;     
                      }
                      
                      
                      case 4:
                      {
                           int m;
                           cout<<"Unesite red matrice(kljuca) pomocu koje zelite sifrirati: ";
                           cin>>m;
                           
                           MatrixXi A(m,m);
                           for(int i=0; i<m; i++)
                                   for(int j=0; j<m; j++)
                                   {
                                           cout<<"Unesite a"<<i+1<<j+1<<": ";
                                           cin>>A(i,j);    
                                   }
                                   
                           string plaintxt;
                           cin.ignore();
	                       cout<<"Unesite tekst koji zelite sifrirati: ";
	                       getline(cin, plaintxt);
                      	   int n =plaintxt.size();
                      	   while(n%m!=0)
                      	                n++;
                      	                
	                       int numberPlainTxt[n];
	                       int polje=n;
                           for (int i=0;i<n;i++);
                           numberPlainTxt[n]=25;

                           string abeceda = "abcdefghijklmnopqrstuvwxyz";
	                       string ChiperTxt;
	
	                       for (int i = 0; i < n; i++)
                           {
                               for (int j = 0; j<26; j++)
                               {
                                   if (plaintxt[i] == abeceda[j])
				                   {
                                      numberPlainTxt[i] = j;	
                                   }
                               }
	                       }
	                       
		                   VectorXi jedVector(m,1), rezultat(m,1);
		                   int numberChiperTxt[n];
		                   int tmpBrojac = 0;
                           int pombrojac=0;
		                   for (int i = 0; i < n; i+=m)
		                   {
			                  for(int j=0;j<m;j++)
                                   for (int k=0;k<1;k++){
                                       jedVector(j,k)=numberPlainTxt[pombrojac];
                                       pombrojac++;}
		                               rezultat = A * jedVector ;
		                               for (int r = 0; r < m; r++)
		                               {
		    	                           for (int s = 0; s < 1; s++)
                                           {
		                                       int tmp,modulo;
	                                           tmp = rezultat (r,s);
		    		                           modulo = tmp % 26;
		    		                           rezultat(r,s) = modulo;
		    		                           numberChiperTxt[tmpBrojac] = modulo;
		    		                           tmpBrojac++;
   	                                           }
                                               }
                           }
		                   cout<<"Sifrirani tekst: "<<endl;
		                   for (int i = 0; i < n; i ++)
		                   {
                               int tmpslovo = 0;
			                   tmpslovo = numberChiperTxt[i];					
			                   cout << abeceda[tmpslovo];
		                    }
		                    cout<<endl;
		                    
		                    
		                    
                           break;
                      }
                      
                      
                      case 5:
                           {
                                 int m;
                                 cout<<"Unesite red matrice(kljuca) pomocu koje je tekst sifriran: ";
                                 cin>>m;
                           
                                 MatrixXd matrica(m,m);
                                 for(int i=0; i<m; i++)
                                         for(int j=0; j<m; j++)
                                         {
                                                 cout<<"Unesite a"<<i+1<<j+1<<": ";
                                                 cin>>matrica(i,j);    
                                         }
                                 
                                 int determinanta=(int)(matrica.determinant());
                                 int pret= pretvorba(determinanta, mod26);
                                 int provjera = multi_inverz(pret, mod26);
                                 if(provjera==-1)
                                           cout<<"Matrica nema inverz!"<<endl;
                                 else
                                 {
                                     MatrixXi inverz = modulo_inverz(matrica, provjera, m, mod26);
                                  
                                 
                                 MatrixXi A = inverz;
                                 string plaintxt;
                                 cin.ignore();
	                             cout<<"Unesite tekst koji zelite desifrirati: ";
	                             getline(cin, plaintxt);
                      	         int n =plaintxt.size();
                      	         while(n%m!=0)
                      	                      n++;
	                             int numberPlainTxt[n];
	                             int polje=n;
                                 for (int i=0;i<n;i++);
                                 numberPlainTxt[n]=25;

                                 string abeceda = "abcdefghijklmnopqrstuvwxyz";
	                             string ChiperTxt;
	
	                             for (int i = 0; i < n; i++)
                                 {
                                     for (int j = 0; j<26; j++)
                                     {
                                         if (plaintxt[i] == abeceda[j])
                                         {
                                            numberPlainTxt[i] = j;	
                                         }
                                     }
                                 }
                                       
                              VectorXi jedVector(m,1), rezultat(m,1);
		                       int numberChiperTxt[n];
		                       int tmpBrojac = 0;
                               int pombrojac=0;
                           
		                       for (int i = 0; i < n; i+=m)
		                       {
			                       for(int j=0;j<m;j++)
                                           for (int k=0;k<1;k++){
                                               jedVector(j,k)=numberPlainTxt[pombrojac];
                                               pombrojac++;}
                                           rezultat = A * jedVector ;
		                                   for (int r = 0; r < m; r++)
		                                   {
		    	                            for (int s = 0; s < 1; s++)
                                            {
		                                       int tmp,modulo;
	                                           tmp = rezultat (r,s);
		    		                           modulo = tmp % 26;
		    		                           rezultat(r,s) = modulo;
		    		                           numberChiperTxt[tmpBrojac] = modulo;
		    		                           tmpBrojac++;
                                               }
                                               }
                          }
                          cout<<"Desifrirani tekst: "<<endl;
                          for (int i = 0; i < n; i ++)
		                   {
                               int tmpslovo = 0;
			                   tmpslovo = numberChiperTxt[i];					
			                   cout << abeceda[tmpslovo];
		                    }
		                    cout<<endl;
                                       }
                                 
                                 break;
                           }
                                           
                   }
    }while(izbor!=9);

       return 0;
}
