import smtplib
import base64

try:
    smtpObj = smtplib.SMTP()
    smtpObj.set_debuglevel(1)
    smtpObj.connect(r'smtp.sina.com', 25)
    smtpObj.docmd("EHLO server")
    smtpObj.login()
    smtpObj.sendmail("hbdhj@sina.com", "haijun.deng@viavisolution.com", "Just for test sendMail via python")
    smtpObj.quit()
    print("Successfully sent email")
except Exception:
    print("Error: unable to send email")