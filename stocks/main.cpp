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
#include <curl/curl.h>
#include "rapidxml.hpp"

using namespace rapidxml;	

//gets the page using curl
void get_page( const char* url, const char* file_name )
{
    CURL* easyhandle = curl_easy_init() ;
    
    curl_easy_setopt( easyhandle, CURLOPT_URL, url ) ;
    
    std::FILE* file = std::fopen( file_name, "w" ) ;
    curl_easy_setopt( easyhandle, CURLOPT_WRITEDATA, file ) ;
    
    curl_easy_perform( easyhandle );
    
    curl_easy_cleanup( easyhandle );
    
    fclose(file);
    
}

int main(int argc, const char * argv[])
{
    /*
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
    */
    
    //get_page( "http://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20yahoo.finance.quotes%20where%20symbol%20in%20(%22YHOO%22%2C%22AAPL%22%2C%22GOOG%22%2C%22MSFT%22)&diagnostics=true&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys", "/Users/lavingiasa/Dropbox/Personal/stocks/stocks/downloads.xml" ) ;
    
    std::cout << "Parsing my stocks file... \n" << std::endl;
	xml_document<> doc;
	xml_node<> * root_node;
    std::ifstream theFile ("/Users/lavingiasa/Dropbox/Personal/stocks/stocks/downloads.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    
	buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    
    root_node = doc.first_node("query");
    xml_node<> * results = root_node->first_node("results");
    std::vector<std::vector<std::string> *> stocksVector;
    
    //looks at the name of each node and puts the arrtibutes in a vector
    for (xml_node<> * stock = results->first_node("quote"); stock; stock = stock->next_sibling())
	{
        std::vector<std::string> * current = new std::vector<std::string>;
        printf("Stock Name: %s \n", stock->first_attribute("symbol")->value());
        current->push_back(stock->first_attribute("symbol")->value());
        
        printf("AverageDailyVolume: %s \n", stock->first_node("AverageDailyVolume")->value());
        current->push_back(stock->first_node("AverageDailyVolume")->value());

        printf("Bid: %s \n", stock->first_node("Bid")->value());
        current->push_back(stock->first_node("Bid")->value());
        
        printf("Ask: %s \n", stock->first_node("Ask")->value());
        current->push_back(stock->first_node("Ask")->value());
        
        printf("AskRealtime: %s \n", stock->first_node("AskRealtime")->value());
        current->push_back(stock->first_node("AskRealtime")->value());
        
        printf("BidRealtime: %s \n", stock->first_node("BidRealtime")->value());
        current->push_back(stock->first_node("BidRealtime")->value());
        
        printf("BookValue: %s \n", stock->first_node("BookValue")->value());
        current->push_back(stock->first_node("BookValue")->value());
        
        printf("Change_PercentChange: %s \n", stock->first_node("Change_PercentChange")->value());
        current->push_back(stock->first_node("Change_PercentChange")->value());
        
        printf("Change: %s \n", stock->first_node("Change")->value());
        current->push_back(stock->first_node("Change")->value());
        
        printf("ChangeRealtime: %s \n", stock->first_node("ChangeRealtime")->value());
        current->push_back(stock->first_node("ChangeRealtime")->value());
        
        printf("AfterHoursChangeRealtime: %s \n", stock->first_node("AfterHoursChangeRealtime")->value());
        current->push_back(stock->first_node("AfterHoursChangeRealtime")->value());
        
        printf("DividendShare: %s \n", stock->first_node("DividendShare")->value());
        current->push_back(stock->first_node("DividendShare")->value());
        
        printf("LastTradeDate: %s \n", stock->first_node("LastTradeDate")->value());
        current->push_back(stock->first_node("LastTradeDate")->value());
        
        printf("EarningsShare: %s \n", stock->first_node("EarningsShare")->value());
        current->push_back(stock->first_node("EarningsShare")->value());
        
        printf("EPSEstimateCurrentYear: %s \n", stock->first_node("EPSEstimateCurrentYear")->value());
        current->push_back(stock->first_node("EPSEstimateCurrentYear")->value());
        
        printf("EPSEstimateNextYear: %s \n", stock->first_node("EPSEstimateNextYear")->value());
        current->push_back(stock->first_node("EPSEstimateNextYear")->value());
        
        printf("EPSEstimateNextQuarter: %s \n", stock->first_node("EPSEstimateNextQuarter")->value());
        current->push_back(stock->first_node("EPSEstimateNextQuarter")->value());
        
        printf("DaysLow: %s \n", stock->first_node("DaysLow")->value());
        current->push_back(stock->first_node("DaysLow")->value());
        
        printf("DaysHigh: %s \n", stock->first_node("DaysHigh")->value());
        current->push_back(stock->first_node("DaysHigh")->value());
        
        printf("YearLow: %s \n", stock->first_node("YearLow")->value());
        current->push_back(stock->first_node("YearLow")->value());
        
        printf("YearHigh: %s \n", stock->first_node("YearHigh")->value());
        current->push_back(stock->first_node("YearHigh")->value());
        
        printf("HoldingsGainPercent: %s \n", stock->first_node("HoldingsGainPercent")->value());
        current->push_back(stock->first_node("HoldingsGainPercent")->value());
        
        printf("MarketCapitalization: %s \n", stock->first_node("MarketCapitalization")->value());
        current->push_back(stock->first_node("MarketCapitalization")->value());
        
        printf("EBITDA: %s \n", stock->first_node("EBITDA")->value());
        current->push_back(stock->first_node("EBITDA")->value());
        
        printf("ChangeFromYearLow: %s \n", stock->first_node("ChangeFromYearLow")->value());
        current->push_back(stock->first_node("ChangeFromYearLow")->value());
        
        printf("PercentChangeFromYearLow: %s \n", stock->first_node("PercentChangeFromYearLow")->value());
        current->push_back(stock->first_node("PercentChangeFromYearLow")->value());
        
        printf("LastTradeRealtimeWithTime: %s \n", stock->first_node("LastTradeRealtimeWithTime")->value());
        current->push_back(stock->first_node("LastTradeRealtimeWithTime")->value());
        
        printf("ChangePercentRealtime: %s \n", stock->first_node("ChangePercentRealtime")->value());
        current->push_back(stock->first_node("ChangePercentRealtime")->value());
        
        printf("ChangeFromYearHigh: %s \n", stock->first_node("ChangeFromYearHigh")->value());
        current->push_back(stock->first_node("ChangeFromYearHigh")->value());
        
        printf("PercebtChangeFromYearHigh: %s \n", stock->first_node("PercebtChangeFromYearHigh")->value());
        current->push_back(stock->first_node("PercebtChangeFromYearHigh")->value());
        
        printf("LastTradeWithTime: %s \n", stock->first_node("LastTradeWithTime")->value());
        current->push_back(stock->first_node("LastTradeWithTime")->value());
        
        printf("LastTradePriceOnly: %s \n", stock->first_node("LastTradePriceOnly")->value());
        current->push_back(stock->first_node("LastTradePriceOnly")->value());
        
        printf("DaysRange: %s \n", stock->first_node("DaysRange")->value());
        current->push_back(stock->first_node("DaysRange")->value());
        
        printf("DaysRangeRealtime: %s \n", stock->first_node("DaysRangeRealtime")->value());
        current->push_back(stock->first_node("DaysRangeRealtime")->value());
        
        printf("FiftydayMovingAverage: %s \n", stock->first_node("FiftydayMovingAverage")->value());
        current->push_back(stock->first_node("FiftydayMovingAverage")->value());
        
        printf("TwoHundreddayMovingAverage: %s \n", stock->first_node("TwoHundreddayMovingAverage")->value());
        current->push_back(stock->first_node("TwoHundreddayMovingAverage")->value());
        
        printf("ChangeFromTwoHundreddayMovingAverage: %s \n", stock->first_node("ChangeFromTwoHundreddayMovingAverage")->value());
        current->push_back(stock->first_node("ChangeFromTwoHundreddayMovingAverage")->value());
        
        printf("PercentChangeFromTwoHundreddayMovingAverage: %s \n", stock->first_node("PercentChangeFromTwoHundreddayMovingAverage")->value());
        current->push_back(stock->first_node("PercentChangeFromTwoHundreddayMovingAverage")->value());
        
        printf("ChangeFromFiftydayMovingAverage: %s \n", stock->first_node("ChangeFromFiftydayMovingAverage")->value());
        current->push_back(stock->first_node("ChangeFromFiftydayMovingAverage")->value());
        
        printf("PercentChangeFromFiftydayMovingAverage: %s \n", stock->first_node("PercentChangeFromFiftydayMovingAverage")->value());
        current->push_back(stock->first_node("PercentChangeFromFiftydayMovingAverage")->value());
        
        printf("Open: %s \n", stock->first_node("Open")->value());
        current->push_back(stock->first_node("Open")->value());
        
        printf("PreviousClose: %s \n", stock->first_node("PreviousClose")->value());
        current->push_back(stock->first_node("PreviousClose")->value());
        
        printf("ChangeinPercent: %s \n", stock->first_node("ChangeinPercent")->value());
        current->push_back(stock->first_node("ChangeinPercent")->value());
        
        printf("PriceSales: %s \n", stock->first_node("PriceSales")->value());
        current->push_back(stock->first_node("PriceSales")->value());
        
        printf("PERatio: %s \n", stock->first_node("PERatio")->value());
        current->push_back(stock->first_node("PERatio")->value());
        
        printf("PEGRatio: %s \n", stock->first_node("PEGRatio")->value());
        current->push_back(stock->first_node("PEGRatio")->value());
        
        printf("PriceEPSEstimateCurrentYear: %s \n", stock->first_node("PriceEPSEstimateCurrentYear")->value());
        current->push_back(stock->first_node("PriceEPSEstimateCurrentYear")->value());
        
        printf("PriceEPSEstimateNextYear: %s \n", stock->first_node("PriceEPSEstimateNextYear")->value());
        current->push_back(stock->first_node("PriceEPSEstimateNextYear")->value());
        
        printf("ShortRatio: %s \n", stock->first_node("ShortRatio")->value());
        current->push_back(stock->first_node("ShortRatio")->value());
        
        printf("OneyrTargetPrice: %s \n", stock->first_node("OneyrTargetPrice")->value());
        current->push_back(stock->first_node("OneyrTargetPrice")->value());
        
        printf("Volume: %s \n", stock->first_node("Volume")->value());
        current->push_back(stock->first_node("Volume")->value());
        
        printf("YearRange: %s \n", stock->first_node("YearRange")->value());
        current->push_back(stock->first_node("YearRange")->value());
        
        printf("DaysValueChange: %s \n", stock->first_node("DaysValueChange")->value());
        current->push_back(stock->first_node("DaysValueChange")->value());
        
        printf("DaysValueChangeRealtime: %s \n", stock->first_node("DaysValueChangeRealtime")->value());
        current->push_back(stock->first_node("DaysValueChangeRealtime")->value());
        
        printf("PercentChange: %s \n", stock->first_node("PercentChange")->value());
        current->push_back(stock->first_node("PercentChange")->value());

        stocksVector.push_back(current);
        //puts hte vecktor in a vector
        
        
        std::cout << std::endl << std::endl;
	}
    
    return 0;
}

