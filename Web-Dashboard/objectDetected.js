const channelID = "2677079";  
const readAPIKey = "S3SEY2U7EY8VELQX";  

async function fetchObjectDetected() {
    const response = await fetch(`https://api.thingspeak.com/channels/${channelID}/fields/4.json?api_key=${readAPIKey}&results=1`);
    const data = await response.json();
    
    if (data.feeds.length > 0) {
        const latestData = data.feeds[0];
        document.getElementById("objectDetected").innerText = latestData.field4 == 1 ? "Object Detected" : "No Object Detected";
    }
}

fetchObjectDetected();
setInterval(fetchObjectDetected, 2000);
