#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>


static void dump_elements(xmlNodePtr n);

int main()
{
        const char filename[] = "sample2xml.xml";
        xmlDocPtr doc;
        xmlNodePtr node;

        doc = xmlParseFile(filename);
        if(doc==NULL)
        {
           fprintf(stderr,"Unable to process %s\n",filename);
           exit(1);
        }
        node = xmlDocGetRootElement(doc);
        if(node == NULL)
        {
           fprintf(stderr,"Document %s is empty\n",filename);
           xmlFreeDoc(doc);
           exit(1);
        }

        printf("root node is %s\n",node->name);

        dump_elements(node);
        xmlFreeDoc(doc);

        return(0);
}


static void dump_elements(xmlNodePtr n)
{
        xmlNodePtr current;
        xmlChar* attribute;

        for(current = n;current;current=current->next)
        {
                if(current->type==XML_ELEMENT_NODE)
                {
                        printf("Node: %s", current->name);
                        attribute = xmlGetProp(current,(const xmlChar*)"type");
                        if(attribute!=NULL)
                                printf(" Attribute: %s", attribute);
                        xmlFree(attribute);
                        putchar('\n');
                }
                dump_elements(current->children);
        }

}