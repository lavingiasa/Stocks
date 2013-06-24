//
//  main.cpp
//  stocks
//
//  Created by Samir Lavingia on 5/25/13.
//  Copyright (c) 2013 Samir Lavingia. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"

using namespace rapidxml;	

int main(int argc, const char * argv[])
{

    std::cout << "Parsing my beer journal..." << std::endl;
	xml_document<> doc;
	xml_node<> * root_node;
    std::ifstream theFile ("/Users/lavingiasa/Dropbox/Personal/stocks/stocks/test.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    
	buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    
    root_node = doc.first_node("MyBeerJournal");

    for (xml_node<> * brewery_node = root_node->first_node("Brewery"); brewery_node; brewery_node = brewery_node->next_sibling())
	{
	    printf("I have visited %s in %s. ",
               brewery_node->first_attribute("name")->value(),
               brewery_node->first_attribute("location")->value());
        // Interate over the beers
	    for(xml_node<> * beer_node = brewery_node->first_node("Beer"); beer_node; beer_node = beer_node->next_sibling())
	    {
	    	printf("On %s, I tried their %s which is a %s. ",
                   beer_node->first_attribute("dateSampled")->value(),
                   beer_node->first_attribute("name")->value(),
                   beer_node->first_attribute("description")->value());
	    	printf("I gave it the following review: %s", beer_node->value());
	    }
        std::cout << std::endl;
	}
    
    return 0;
}

