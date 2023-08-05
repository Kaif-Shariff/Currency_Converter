const fromCurr = document.getElementById("fromCurr");
const toCurr = document.getElementById("toCurr");
const conBtn = document.getElementById("convertBtn");
const currInput = document.getElementById("curr-input");

async function getData() {
  const response = await fetch(
    "https://v6.exchangerate-api.com/v6/68a41441480d78ccdb2ebc5c/latest/USD"
  );
  let data = await response.json();
  return data.conversion_rates;
}
getData();

async function setOptionValue() {
  const currencies = await getData();

  for (currency in currencies) {
    let optionFrom = document.createElement("option");
    optionFrom.value = currency;
    optionFrom.textContent = currency;
    fromCurr.appendChild(optionFrom);

    let optionTo = document.createElement("option");
    optionTo.value = currency;
    optionTo.textContent = currency;
    toCurr.appendChild(optionTo);
  }
}
setOptionValue();

conBtn.addEventListener("click", async () => {
  if (currInput.value == "") {
    alert("No input!");
  } else if (currInput.value < 0) {
    alert("Cannot Convert Negative Number");
  } else if (fromCurr.value == toCurr.value) {
    alert("Can't convert to same currency!");
  } else {
    const conversionRate = await getData();
    const amount = parseFloat(currInput.value);
    const FromRate = conversionRate[fromCurr.value];
    const ToRate = conversionRate[toCurr.value];

    const convertedAmt = (amount / FromRate) * ToRate;

    const outputTxt = document.getElementById('outTxt');
    outputTxt.innerText = convertedAmt.toFixed(2);
  }
});
