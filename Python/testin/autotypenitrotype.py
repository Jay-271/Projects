import time
from selenium import webdriver
from bs4 import BeautifulSoup
import pyautogui
import keyboard
from selenium_stealth import stealth

def main():
    options = webdriver.ChromeOptions()
    stealth(options)
    
    browser = webdriver.Chrome(executable_path=r'chromedriver_win32\chromedriver.exe',chrome_options=options)
    
    # Value for the URL
    url = "https://www.nitrotype.com/race"
    browser.get(url)
    
    time.sleep(11)
    """
    page_source = browser.page_source
    
    soup = BeautifulSoup(page_source, "html.parser")
    spans = soup.find_all('span', class_='dash-letter')
    #print(spans)
    
    text_to_type = ''.join([span.get_text().replace('\xa0', ' ') for span in spans])
    
    print(text_to_type)
    
    time.sleep(2)
    pyautogui.write(text_to_type, interval=0)
    
    """
    print("Press 'q' to exit.")

    while True:
        if keyboard.is_pressed('DELETE'):
            page_source = browser.page_source
    
            soup = BeautifulSoup(page_source, "html.parser")
            spans = soup.find_all('span', class_='dash-letter')
            #print(spans)
    
            text_to_type = ''.join([span.get_text().replace('\xa0', ' ') for span in spans])
    
            print(text_to_type)
    
            time.sleep(2)
            pyautogui.write(text_to_type, interval=0)
    
            print("Press 'q' to exit.")
            continue
        elif keyboard.is_pressed('q'):
            break
        
        time.sleep(1)
    
    # Close the browser and quit the WebDriver
    browser.quit()

if __name__ == "__main__":
    main()
