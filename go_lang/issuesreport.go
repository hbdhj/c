const temp1 = `{{.TotalCount}}
issues: {{range .Items}}-------------
Number: {{.Number}}
User: {{.User.Login}}
Title: {{.Title | printf "%.64s"}}
Age: {{.CreateAt | daysAgo}}
days
{{end}}`

func daysAgo (t time.Time) int {
    return int(time.Since(t).Hours()/24)
}

report, err := template.New("report").Funcs(template.FuncMap{"daysAgo": daysAgo}).Parse(temp1)

if err != nil {
    log.Fatal(err)
}

var report = template.Must(template.New("issuelist")).Funcs(template.FuncMap{"daysAgo": daysAgo}).Parse(temp1)

func main() {
    result, err := github.SearchIssues(os.Args[1:])
    if err != nil {
        log.Fatal(err)
    }
}
