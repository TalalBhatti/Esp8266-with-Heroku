var express = require('express');
var app = express();
var Firebase = require('firebase')


app.use(express.static(__dirname + '/views'));
app.use('/static', express.static(__dirname + '/public'));

Firebase.initializeApp({

  databaseURL: "https://nodemcubuzzer-5390a-default-rtdb.firebaseio.com/",
  serviceAccount: "./service-account.json",

});


let database = Firebase.database()

var usersRef = database.ref("users");

app.get('/', function(req, res) {
  res.render('index')
});

app.post('/updateled',(req,res)=> {
  usersRef.set({
    BUZZER: 0 
  });
})

app.listen(8080);