#pragma once
#include <string>
#include <vector>

template <typename Iterator>
class Paginator {
public:
    Paginator(Iterator range_begin, Iterator range_end, const uint32_t  page_size) {
    	int count_page;
        if (page_size > distance(range_begin, range_end)) {
            std::string page;
            for (auto it = range_begin; it != range_end; ++it) {
                page +=PrintDocumentToString(*it);
            }
            pages_.push_back(page);
        }
        else if (distance(range_begin, range_end) % page_size == 0) {
            count_page = distance(range_begin, range_end) / page_size;
            auto it_begin = range_begin;
            auto it_end = it_begin + page_size;
            for(size_t i = 0; i < count_page; ++i)
            {
                std::string page;
                for (auto it = it_begin; it < it_end; ++it) {
                    page +=PrintDocumentToString(*it);
                }
                pages_.push_back(page);
                it_begin += page_size;
                it_end += page_size;
            }
        } else {
            count_page = distance(range_begin, range_end) / page_size + 1;
            auto it_begin = range_begin;
            auto it_end = it_begin + page_size;
            for(size_t i = 0; i < count_page; ++i)
            {
		std::string page;
                for (auto it = it_begin; it < it_end; ++it) {
                    page +=PrintDocumentToString(*it);
                }
                pages_.push_back(page);
                it_begin += page_size;
                if (it_end + page_size > range_end) {
                    it_end = range_end;
                } else {
                    it_end += page_size;
                }
            }
        }
    }
    
    std::vector<std::string> GetPages() {
    return pages_;
    }
    
private:
    vector<string> pages_;
}; 
