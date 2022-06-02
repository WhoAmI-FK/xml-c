#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

int main(){
        const char filename[] = "samplexml.xml";

        xmlDocPtr doc;

        doc = xmlParseFile(filename);
        if(doc==NULL)
        {
          fprintf(stderr,"Unable to parse document %s\n",filename);
          exit(1);
        }
        if(doc->version!=NULL && doc->encoding!=NULL)
        {
          printf("%s is XML version %s with %s encoding\n",
                filename,
                doc->version,
                doc->encoding
                );

        }else
        {
                printf("%s lacks either XML version of encoding information\n",filename);

        }
        xmlFreeDoc(doc);


        return (0);

}