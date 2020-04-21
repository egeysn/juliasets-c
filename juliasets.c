#include <stdio.h>
#include <complex.h>
#define K 75
void main()
{
    complex double z, c;
    float a, b;
    int i;
    int myWidth = 2048;
    int myHeight = 2048;
    double xmin = -1.5, xmax = 1.5;
    double ymin=-1.5, ymax= 1.5;
	double xwidth = xmax-xmin;
	double yheight = ymax-ymin;

    FILE* pgmimg; 
    pgmimg = fopen("k75.pgm", "wb");
	 // Writing Magic Number to the File 
    fprintf(pgmimg, "P2\n");  
	   // Writing Width and Height 
    fprintf(pgmimg, "%d %d\n", 2048, 2048); 
     fprintf(pgmimg, "255\n");  
    //printf("P2\n4000 4000\n255\n");
	int min = cabs(z);
    for (a=0 ; a<2048 ; ++a)
    {
        for (b=0 ; b<2048 ; ++b)
        {
           // c =  0.101 + 0.482*I;   //c1) 0048 X = 0, Y= 1, Z=4 ,W = 8     XY = 0 old için =1 deðeri kullanýldý  ögr no son 4 hane= 0048
            //c =  (0.110 )- (1.048)*I;  /c2
             //c = -(0.101) + (0.482)*I;  // c3);
            c = (0.01)-(0.8410)*I;  //c4
             z = ((a / myWidth )* xwidth +xmin) + ((b / myHeight)*yheight+ymin)*I;
             i = 0;
            // printf(" cabsz Baþlangic - %f - ,",cabs(z));
             while (cabs(z) < 4 && i < K){ //k = 75
             	z = z*z + c;	
             	i++;
             	/*
             	if(cabs(z) < min ){
             		min = cabs(z); //EN KÜÇÜK SAYIYI BULMA
				 }
				 */
			 } 
			  if(i == K) {
	                 fprintf(pgmimg, "0\t"); 
              } else {
           
           	fprintf(pgmimg, "255\t"); 
        }
            
        }
        fprintf(pgmimg, "\n"); 
       // printf("\n");
    }
       fclose(pgmimg);  
}

