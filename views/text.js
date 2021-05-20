function timer1(){
  var d = parseInt(document.getElementById("days").value, 0);
  var h = parseInt(document.getElementById("hours").value, 0);
  var m = parseInt(document.getElementById("minutes").value, 0);
  var s = parseInt(document.getElementById("seconds").value, 0);

  let current = ((d * 86400) + (h * 3600) + (m * 60) + s);  //the current time left in seconds
  return current
}

var input_time= timer1()
console.log(input_time)
const finaleDate = new Date().getTime() + input_time;

console.log(finaleDate)
const timer = () =>{
    const now = new Date().getTime();
    // console.log(now)
    let diff = finaleDate - now;
    // Showing the alert when the counter time finishes.
    if(diff < 0){
        document.querySelector('.alert').style.display = 'block';
        document.querySelector('.container').style.display = 'none';
    }
    
    let days = Math.floor(diff / (1000*60*60*24));
    let hours = Math.floor(diff % (1000*60*60*24) / (1000*60*60));
    let minutes = Math.floor(diff % (1000*60*60)/ (1000*60));
    let seconds = Math.floor(diff % (1000*60) / 1000);
  // Adding the zeros.
    days <= 99 ? days = `0${days}` : days;
    days <= 9 ? days = `00${days}` : days;
    hours <= 9 ? hours = `0${hours}` : hours;
    minutes <= 9 ? minutes = `0${minutes}` : minutes;
    seconds <= 9 ? seconds = `0${seconds}` : seconds;   

    document.querySelector('#days').textContent = days;
    document.querySelector('#hours').textContent = hours;
    document.querySelector('#minutes').textContent = minutes;
    document.querySelector('#seconds').textContent = seconds;

}
timer();
// Calling the function every 1000 milliseconds.
setInterval(timer,1000);


