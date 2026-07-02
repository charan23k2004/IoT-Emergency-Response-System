const channelID = "2677079";  // Your ThingSpeak Channel ID
const readAPIKey = "S3SEY2U7EY8VELQX";  // Your ThingSpeak Read API Key

async function fetchTemperature() {
    const response = await fetch(`https://api.thingspeak.com/channels/${channelID}/fields/1.json?api_key=${readAPIKey}&results=1`);
    const data = await response.json();
    
    if (data.feeds.length > 0) {
        const latestData = data.feeds[0];
        document.getElementById("temperature").innerText = latestData.field1 + " °C";
    }
}

fetchTemperature();
setInterval(fetchTemperature, 5000);
