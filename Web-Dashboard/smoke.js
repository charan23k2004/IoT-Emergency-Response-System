const channelID = "2677079";  
const readAPIKey = "S3SEY2U7EY8VELQX";  

async function fetchSmokeLevel() {
    const response = await fetch(`https://api.thingspeak.com/channels/${channelID}/fields/3.json?api_key=${readAPIKey}&results=1`);
    const data = await response.json();
    
    if (data.feeds.length > 0) {
        const latestData = data.feeds[0];
        document.getElementById("smoke").innerText = latestData.field3;
    }
}

fetchSmokeLevel();
setInterval(fetchSmokeLevel, 5000);
