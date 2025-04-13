#include<fstream>
#include <iostream>
#include <ctime>

int main(int argc, char* argv[]) {

  if (argc < 2) {
    std::cout << "No argument have been provided\n";
    return 1;
  } else if (argc < 3) {
    std::cout << "No rss file have been provided\n";
  } else if (argc < 4) {
    std::cout << "No rss title have been provided\n";
  } else if (argc < 5) {
    std::cout << "No rss link have been provided\n";
  };

  std::string html_file = argv[1];
  std::string xml_file = argv[2];
  std::string title = argv[3];
  std::string link = argv[4];

  std::string pubDate;
  time_t cur_time;
  std::time(&cur_time);

  if (argc < 6) {
    pubDate = std::ctime(&cur_time);
  } else {
    pubDate = argv[5];
  };

  std::fstream r_html(html_file);

  std::string currow;
  std::string html_data = "";
  std::string xml_data = "";
  std::string now_currow;

  unsigned int i;
  unsigned int add_cnt;
  unsigned int n;

  while (getline(r_html, currow)) {
    now_currow = currow;
    add_cnt = 0;
    n = now_currow.length();
    i = 0;
    while (i < n) {
      if (now_currow[i + add_cnt] == '<') {
        now_currow.erase(now_currow.begin() + i + add_cnt);
        now_currow.insert(now_currow.begin() + i + add_cnt, '&');
        now_currow.insert(now_currow.begin() + i + add_cnt + 1, 'l');
        now_currow.insert(now_currow.begin() + i + add_cnt + 2, 't');
        now_currow.insert(now_currow.begin() + i + add_cnt + 3, ';');
        add_cnt += 3;
      } else if (now_currow[i + add_cnt] == '>') {
        now_currow.erase(now_currow.begin() + i + add_cnt);
        now_currow.insert(now_currow.begin() + i + add_cnt, '&');
        now_currow.insert(now_currow.begin() + i + add_cnt + 1, 'g');
        now_currow.insert(now_currow.begin() + i + add_cnt + 2, 't');
        now_currow.insert(now_currow.begin() + i + add_cnt + 3, ';');
        add_cnt += 3;
      };
      i += 1;
    };
    html_data += now_currow;
    html_data.push_back('\n');
  };
  r_html.close();

  std::fstream r_xml(xml_file);
  while(getline(r_xml, currow)) {
    if (currow[0] == '?') {
      xml_data.pop_back();
      xml_data += "\n<item>\n";
      xml_data += ("<title>" + title + "</title>\n");
      xml_data += ("<link>" + link + "</link>\n");
      xml_data += ("<pubDate>" + pubDate + "</pubDate>\n");
      xml_data += "<description>";
      xml_data += html_data;
      xml_data += "\n</description>";
      xml_data += "\n</item>";
    } else {
      xml_data += currow;
    };
    xml_data.push_back('\n');
  };
  r_xml.close();

  std::fstream o_xml(xml_file, std::ios::out);
  o_xml << xml_data;
  o_xml.close();

  return 0;
};


