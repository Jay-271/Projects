import time
from selenium import webdriver
from bs4 import BeautifulSoup
import pyautogui
import keyboard

def main():
    browser = webdriver.Chrome()
    
    # Value for the URL
    url = "http://humanbenchmark.com/tests/typing"
    browser.get(url)
    
    time.sleep(5)
    
    page_source = browser.page_source
    
    soup = BeautifulSoup(page_source, "html.parser")
    spans = soup.find_all('span', class_='incomplete')
    #print(spans)
    
    text_to_type = ''.join([span.get_text() for span in spans])
    print(text_to_type)
    
    time.sleep(2)
    pyautogui.write(text_to_type, interval=0)
    
    print("Press 'q' to exit.")
    
    while True:
        if keyboard.is_pressed('DELETE'):
            break
        time.sleep(1)
    
    # Close the browser and quit the WebDriver
    browser.quit()

if __name__ == "__main__":
    main()
