#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

void parseKeyword(xmlDocPtr d, xmlNodePtr n, char* keyword);

int main()
{
        const char filename[] = "sample2xml.xml";
        xmlDocPtr doc;
        xmlNodePtr node;

        doc = xmlParseFile(filename);
        if(doc == NULL)
        {
                fprintf(stderr, "Unable to parse document %s\n",filename);
                exit(1);
        }
        node = xmlDocGetRootElement(doc);
        if(node == NULL)
        {
                fprintf(stderr, "Document %s is empty\n",filename);
                xmlFreeDoc(doc);
                exit(1);
        }
        node = node->children;
        while(node != NULL)
        {
                if((!xmlStrcmp(node->name,(const xmlChar*)"name")))
                        parseKeyword(doc,node,"first");
                node = node->next;
        }

        xmlFreeDoc(doc);
        return(0);
}

void parseKeyword(xmlDocPtr d, xmlNodePtr n, char* keyword)
{
        xmlChar* key;
        n = n->children;
        while(n!=NULL)
        {
                if((!xmlStrcmp(n->name,(const xmlChar*) keyword)))
                {
                        key = xmlNodeListGetString(d, n->children, 1);
                        printf("Name, First: %s\n",key);
                        xmlFree(key);
                }
                n = n->next;
        }
}