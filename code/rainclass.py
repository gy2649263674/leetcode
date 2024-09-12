import requests
from selenium import webdriver
url = "https://www.yuketang.cn/v2/web/cloud/student/exercise/22625017/51490777/11162466"
driver = webdriver.Chrome()
driver.get(url)
driver.download_file(url)
exit()
resp = requests.get("https://www.yuketang.cn/v2/web/cloud/student/exercise/22625017/51490777/11162466",headers={
    "user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36",
    "cookie":"django_language=zh-cn; JG_fcdf8e635093adde6bef42651_PV=1725890676370|1725890681798; login_type=WX; csrftoken=amVTCiMNFoAhdGVhlWmNL9JhLHrqQBAC; sessionid=gjntrmq0i45syrzv9ztic6dxzdyf6ko6; classroomId=22625017; classroom_id=22625017"
})
with open ("rainclass.html","w",encoding="utf-8") as f:
    f.write(resp.text)
    exit()
    
print(resp.text)
