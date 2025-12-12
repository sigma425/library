import requests
from bs4 import BeautifulSoup
import os
import sys
import re
from urllib.parse import urljoin

def extract_problem_letter(title):
    """問題タイトルから問題文字を抽出"""
    # 例: "A - Merge and Increment" -> "A"
    match = re.match(r'^([A-Z])\s*-', title.strip())
    if match:
        return match.group(1)
    return None

def get_samples(contest_id):
    """指定されたコンテストの全問題のサンプルを取得"""
    # 過度なアクセスを防ぐため、tasks_printページを使用
    tasks_print_url = f"https://atcoder.jp/contests/{contest_id}/tasks_print"
    
    print(f"Collecting samples from: {tasks_print_url}")
    response = requests.get(tasks_print_url)
    print(f"Status code: {response.status_code}")
    
    if response.status_code != 200:
        print(f"Error: Could not access contest {contest_id}")
        return
    
    soup = BeautifulSoup(response.text, 'html.parser')
    
    # testsディレクトリを作成
    os.makedirs('tests', exist_ok=True)
    
    # 各問題のセクションを抽出
    problem_divs = soup.find_all('div', class_='col-sm-12')
    
    processed_problems = set()  # 処理済みの問題を追跡
    
    for div in problem_divs:
        # 問題タイトルを探す
        title_elem = div.find('span', class_='h2')
        if not title_elem:
            continue
            
        title = title_elem.get_text().strip()
        problem_letter = extract_problem_letter(title)
        
        if not problem_letter or problem_letter in processed_problems:
            continue
            
        print(f"Processing problem {problem_letter}: {title}")
        processed_problems.add(problem_letter)
        
        # 日本語版のサンプルのみを処理（lang-jaの部分）
        lang_ja_section = div.find('span', class_='lang-ja')
        if not lang_ja_section:
            print(f"  Warning: No Japanese section found for problem {problem_letter}")
            continue
            
        samples = []
        
        # 入力サンプルを探す（日本語版のみ）
        input_sections = lang_ja_section.find_all('h3', string=re.compile(r'入力例'))
        for i, input_section in enumerate(input_sections):
            # 次の<pre>タグを探す
            pre_tag = input_section.find_next('pre')
            if pre_tag:
                input_text = pre_tag.get_text()
                samples.append({'input': input_text, 'output': None, 'index': i})
        
        # 出力サンプルを探す（日本語版のみ）
        output_sections = lang_ja_section.find_all('h3', string=re.compile(r'出力例'))
        for i, output_section in enumerate(output_sections):
            # 次の<pre>タグを探す
            pre_tag = output_section.find_next('pre')
            if pre_tag and i < len(samples):
                output_text = pre_tag.get_text()
                samples[i]['output'] = output_text
        
        # ファイルに保存
        for sample in samples:
            if sample['input'] is not None:
                input_filename = f"tests/{problem_letter}{sample['index']}.in"
                with open(input_filename, 'w', encoding='utf-8') as f:
                    f.write(sample['input'])
                print(f"  Created {input_filename}")
            
            if sample['output'] is not None:
                output_filename = f"tests/{problem_letter}{sample['index']}.out"
                with open(output_filename, 'w', encoding='utf-8') as f:
                    f.write(sample['output'])
                print(f"  Created {output_filename}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python atcoder_sample_collector.py <contest_id>")
        print("Example: python atcoder_sample_collector.py arc202")
        sys.exit(1)
    
    contest_id = sys.argv[1]
    get_samples(contest_id)
    print("Sample collection completed!")

if __name__ == "__main__":
    main()