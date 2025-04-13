# automate_rss

Simple C++ command line programm allowing to transform an input html file and add it into a chosen xml file ready for RSS feed.

## Example

First, open your xml file and put a '?' where you want the content to be added.

```
$ cat rss_data.xml
<?xml version="1.0" encoding = "UTF-8"?>
<rss version="2.0">
  <channel>
    <item>
      <title>test post5</title>
      <link>https://julienlargetpiet.tech</link>
      <description>&lt;b&gt;teste description2&lt;/b&gt; &lt;br&gt;
      &lt;img src="https://julienlargetpiet.tech/static/files/ev_ui2.png"&gt;
      </description>
    </item>
  </channel>
</rss>
$ vim
...added question mark...
$ cat rss_data.xml
<?xml version="1.0" encoding = "UTF-8"?>
<rss version="2.0">
  <channel>
?
    <item>
      <title>test post5</title>
      <link>https://julienlargetpiet.tech</link>
      <description>&lt;b&gt;teste description2&lt;/b&gt; &lt;br&gt;
      &lt;img src="https://julienlargetpiet.tech/static/files/ev_ui2.png"&gt;
      </description>
    </item>
  </channel>
</rss>
```

Compile

```
$ g++ -O3 automate_rss.cpp
```

Now, run the programm

```
$ ./a.out html_data.html rss_data.xml title_of_the_new_item link_to_content pubDate(optional) 
```

>[NOTE]
>When pubDate is not provided, it defaults to the current date




