#

def strip_url_params(url, params_to_strip = []):
    f_s_url=url.split('?')
    if len(f_s_url)==2:
        params_str = f_s_url[1]
        params = params_str.split('&')
        params_dict = {}
        for param_e in params:
            param = param_e.split('=')
            if param[0] not in params_to_strip and param[0] not in params_dict:
                params_dict[param[0]]=param[1]
        #print(params_dict)
        ret_params_str=""
        for key, value in params_dict.items():
            #print(key, value)
            if ret_params_str=="":
                ret_params_str=key+'='+value
            else:
                ret_params_str+='&'+key+'='+value

        return f_s_url[0]+'?'+ret_params_str
    else:
        return url

print(strip_url_params('www.codewars.com?a=1&b=2&a=2')) # returns 'www.codewars.com?a=1&b=2'
print(strip_url_params('www.codewars.com?a=1&b=2&a=2', ['b'])) # returns 'www.codewars.com?a=1'
print(strip_url_params('www.codewars.com', ['b'])) # returns 'www.codewars.com'