import os, sys
import ssl

from urllib import request, error
from bs4 import BeautifulSoup

ssl._create_default_https_context = ssl._create_unverified_context


def load_html():
    local = True

    if local:
        html_path = "html.html"
        with open(html_path, mode="r", encoding='utf8') as file:
            html = file.read()

    else:
        url = ""
        send_headers = {
            'Host': '',
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:53.0) Gecko/20100101 Firefox/53.0',
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
            'Connection': 'keep-alive'
        }

        req = request.Request(url, headers=send_headers)

        response = request.urlopen(req)

        html = response.read()
        # with open("filename.html", mode="wb") as file:
        #     file.write(html)

    return html


def statistic_num(html):
    host = 'https://leetcode.com/'
    soup = BeautifulSoup(html, "lxml")
    tbodys = soup.select('tbody')
    print(len(tbodys))
    tbodys_0 = tbodys[0]

    trs = tbodys_0.select('tr')
    print(len(trs))

    num = 0
    for tr in trs[:]:
        num += 1
        # print(tr)
        tds = tr.select('td')
        if (str(num) != tds[1].get_text()):
            print(tds[1].get_text())
            num = int(tds[1].get_text())


def parse_html(html):
    host = 'https://leetcode.com'
    soup = BeautifulSoup(html, "lxml")

    tbodys = soup.select('tbody')
    tbodys_0 = tbodys[0]
    md_head = '''
| # | Title | OF | Self | AC | DF |
|---| ----- | -------- | ---- | ---------- | ---------- |
|a| b | c | d | e | f |
'''
    trs = tbodys_0.select('tr')
    output_filename = "leetcode_add.md"
    file = open(output_filename, mode='w', encoding='utf8')
    file.write(md_head)

    num_lock = 0

    for tr in trs[:]:
        tds = tr.select('td')
        num = tds[1].get_text().strip()
        titles = tds[2].get_text().strip().split()
        title = ""
        for piece in titles:
            title = title + " " + piece
        title = title.strip()
        Solution = ""
        Acceptance = tds[4].get_text().strip()
        Difficulty = tds[5].get_text().strip()
        # print(num, title, Solution, Acceptance, Difficulty)

        title_url = host + tr.select('a')[0]['href']
        article_url = ""
        try:
            article_url = host + tr.select('a')[1]['href']
            # print(article_url)
        except:
            pass
        # print(title_url)
        i_tag = ""
        i_tags = tr.select('i')
        if i_tags:
            cls = i_tags[0]['class']
            # print(cls[1])
            # print(type(cls[1]))

            if (cls[1] == "fa-lock"):
                num_lock += 1
                # print(num, title)
                i_tag = "L"
        print(article_url)
        print(i_tag)

        if article_url != "" and i_tag == "":
            output = "|" + num + "|[" + title + "](" + title_url + ")|[OF](" + article_url + ")|" + Solution + "|" + Acceptance + "|" + Difficulty + "|\n"
        elif article_url != "" and i_tag != "":
            output = "|" + num + "|[" + title + "](" + title_url + ")  (Lock)|[OF](" + article_url + ")|" + Solution + "|" + Acceptance + "|" + Difficulty + "|\n"
        elif article_url == "" and i_tag == "":
            output = "|" + num + "|[" + title + "](" + title_url + ")|" + "|" + Solution + "|" + Acceptance + "|" + Difficulty + "|\n"
        elif article_url == "" and i_tag != "":

            output = "|" + num + "|[" + title + "](" + title_url + ")  (Lock)|" + "|" + Solution + "|" + Acceptance + "|" + Difficulty + "|\n"

        print(output)
        file.write(output)
    print(num_lock)
    file.close()


def Run():
    if (len(sys.argv) != 1):
        print("args error ...")
        sys.exit(0)

    html = load_html()
    # statistic_num(html)
    parse_html(html)


if __name__ == "__main__":
    Run()
