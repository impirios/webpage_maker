/*DOCUMENTATION
This program is used for creating webpages and this is targetted to the people who do'nt know HTML/CSS
this program will read the content from the "content.txt" file where you will write all the content of
your webpage right now this program is still in the development stage there for it will create only a basic webpage
but inprovements will be  done in the future so stay connected.

created on-3/6/2019
Project by-@yogesh bhardwaj
*/
#include<stdio.h>
#include<string.h>
//please enter the source of the text file in which you have written the data and also the name of the html file you want to make
void style();
void main()
{

  /*This block will read the data from the content.txt file*/
  FILE*fp;
  FILE*fhtml;
  char atr[500],title[50],heading[50];
  char a;
  printf("Hello and welcome to this webpage creater and follow the next steps to create your first webpage\n");
  /* now the file named content.txt will be read where the content of your program is saved if it is not created than create it*/
  fp=fopen("content.txt","r");
  if(fp==NULL)
  {
    printf("Unable to open the content file please add a content file of create a txt file named content.txt and add your data in it\n");
  }
  else
  fgets(atr,500,fp);
  fclose(fp);

/*this block will create your HTML file you will be adding your title and heading in this block which will be added to your webpage */

  fhtml=fopen("index.html","w+");
  printf("Enter the title that you want to give to your webpage\n");
  fgets(title,50,stdin);
  printf("Enter the heading you want to give to your page\n");
  fgets(heading,50,stdin);
  fprintf(fhtml, "<!DOCTYPE html>\n<html>\n\t\t<head>\n\t\t\t<meta charset=\"utf-8\">\n\t\t\t<title>%s</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n\t\t</head>\n",title);
  fprintf(fhtml, "<body>\n<h1 class=\"heading\">%s</h1>\n<p class=\"para\">%s</p>\n</body>\n",heading,atr);
  fprintf(fhtml, "</html" );
  fclose(fhtml);
  printf("Do you want to style your webpage(y/n)\n");
  scanf("%c",&a);
  if(a=='y')
    style();
  else if(a=='n')
    printf("Alright\n");
  printf("Your webpage is created now open it with a browser\n");

}
/*style function will create the style.css file and will add style elements to the webpage*/
void style()
{
  FILE*style;
  char color[20],pcolor[20],fontfamily[20],pfontfamily[20];
  int size,psize;
  style=fopen("style.css","w+");
  printf("What color do you want to give to your heading \n");
  scanf("%s",color);
  printf("What should be the size of your heading\n");
  scanf("%d",&size);
  printf("What font family would you like to add to your heading\n");
  scanf("%s",fontfamily);
  fprintf(style,".heading{color:%s;\nfont-size:%dpx;\nfont-family:%s;\n}\n",color,size,fontfamily);
  printf("Your heading is edited\n");
  printf("What color do you want to give to your data \n");
  scanf("%s",pcolor);
  printf("What should be the size of the text data\n");
  scanf("%d",&psize);
  printf("What font family would you like to add to your data\n");
  scanf("%s",pfontfamily);
  fprintf(style,".para{color:%s;\nfont-size:%dpx;\nfont-family:%s;}\n",pcolor,psize,pfontfamily);
  fclose(style);
}
