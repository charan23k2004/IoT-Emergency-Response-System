const channelID = "2677079";  
const readAPIKey = "S3SEY2U7EY8VELQX";  

async function fetchHumidity() {
    const response = await fetch(`https://api.thingspeak.com/channels/${channelID}/fields/2.json?api_key=${readAPIKey}&results=1`);
    const data = await response.json();
    
    if (data.feeds.length > 0) {
        const latestData = data.feeds[0];
        document.getElementById("humidity").innerText = latestData.field2 + " %";
    }
}

fetchHumidity();
setInterval(fetchHumidity, 5000);
