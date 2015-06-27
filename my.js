$(document).ready(function(){
$("button").click(function(){
$.post("https://data.sparkfun.com/input/KJ1pL2jgjdfEOWp0XVWE?private_key=vzRpJomkmdHK7Wly4pWK",
{
temp: $("#test").val()
},
function(data){
alert("Data: " + $("#test").val() + " sent to sparkfun");
});
});
});
