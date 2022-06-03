#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

int main()
{
        const char filename[] = "sampleg.xml";
        int r;
        xmlDocPtr doc;
        xmlNodePtr root;
        doc = xmlNewDoc((const xmlChar*)"1.0");
        if(doc == NULL)
        {
                fprintf(stderr,"Unable to create new XML document");
                exit(1);
        }
        root = xmlNewDocNode(doc, NULL, (const xmlChar*)"root",NULL);
        if(root == NULL)
        {
                fprintf(stderr,"Unable to create new node\n");
                exit(1);
        }
        xmlDocSetRootElement(doc, root);
        r = xmlSaveFormatFile(filename, doc ,1);
        if( r == -1)
                printf("Unable to create %s\n",filename);
        else
                printf("%s created, %d bytes written\n",filename, r);
        xmlFreeDoc(doc);
        return(0);
}