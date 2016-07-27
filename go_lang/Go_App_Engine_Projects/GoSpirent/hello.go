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

// [START func_root]
func root(w http.ResponseWriter, r *http.Request) {
    if err := mainPageTmpl.ExecuteTemplate(w, "index.html", ""); err != nil {
        http.Error(w, err.Error(), http.StatusInternalServerError)
    }
}
// [END func_root]

var (
    mainPageTmpl = template.Must(template.New("account").ParseFiles("index.html"))
)

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
