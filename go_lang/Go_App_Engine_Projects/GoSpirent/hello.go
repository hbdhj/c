package guestbook

import (
    "html/template"
    "net/http"
    "appengine"
    "appengine/datastore"
)

// [START greeting_struct]
type Account struct {
        Name    string
}
// [END greeting_struct]

func init() {
        http.HandleFunc("/", root)
        http.HandleFunc("/login", login)
}

// guestbookKey returns the key used for all guestbook entries.
func accountKey(c appengine.Context) *datastore.Key {
        // The string "default_guestbook" here could be varied to have multiple guestbooks.
        return datastore.NewKey(c, "Account", "default_guestbook", 0, nil)
}

// [START func_root]
func root(w http.ResponseWriter, r *http.Request) {
    //c := appengine.NewContext(r)
    if err := guestbookTemplate.Execute(w, ""); err != nil {
        http.Error(w, err.Error(), http.StatusInternalServerError)
    }
}
// [END func_root]

var guestbookTemplate = template.Must(template.New("account").Parse(`
<html>
  <head>
    <title>Login Spirent Lunch Management System</title>
    <style type="text/css">
		body{background:#D2D460;text-align:center;}
	</style>
  </head>
  <body>
    <h1 margin-left: auto;
  margin-right: auto;>Welcome to Spirent Lunch Management System</h1>
    <form action="/login" method="post">
        <div margin-left: auto; margin-right: auto;><textarea name="account" rows="1" cols="10"></textarea></div>
        <div><input type="submit" name="action" value="Login"><input type="submit" name="action" value="Create"></div>
    </form>
  </body>
</html>
`))

// [START func_sign]
func login(w http.ResponseWriter, r *http.Request) {
    c := appengine.NewContext(r)
    r.ParseForm();
    if (r.FormValue("action") == "Login") {
        output := "action is login, and account is " + r.FormValue("account")
        newAccountKey := datastore.NewKey(c, "Account", r.FormValue("account"), 0, nil)
        getAccount := new(Account)
        if err := datastore.Get(c, newAccountKey, getAccount); err == nil {
            output += ", login success"
        } else {
            output += ", login failed"
        }
        http.Error(w, output, http.StatusInternalServerError)

        return
    //action for update here
    } else if (r.FormValue("action") == "Create") {
        output := "action is Create, and account is " + r.FormValue("account")
        newAccountKey := datastore.NewKey(c, "Account", r.FormValue("account"), 0, nil)
        getAccount := new(Account)
        if err := datastore.Get(c, newAccountKey, getAccount); err == nil {

        //if accountNum > 0 {
            output += ", account already exist"
        } else {
            newAccount := Account{
                Name: r.FormValue("account"),
            }
            newKey := datastore.NewKey(c, "Account", r.FormValue("account"), 0, nil)
            _, err := datastore.Put(c, newKey, &newAccount)
            if err != nil {
                output += ", create a new account failed"
            } else {
                output += ", create a new account success"
            }
        }
        http.Error(w, output, http.StatusInternalServerError)
        return
    //action for delete
    } else {
        http.Error(w, "unknown action", http.StatusInternalServerError)
        return
    //invalid action!
    }
    // [END if_user]
}
// [END func_sign]
// [START func_sign]
func create(w http.ResponseWriter, r *http.Request) {

        // [END if_user]
}
