let gameSequence = [];
let userSequence = [];
let btns = ["btn1","btn2","btn3","btn4"];

let startFlag = false;
let levelCount = 0;
let HighScore = 0;

document.addEventListener("keypress", function() {

    if(startFlag == false) {
        startFlag = true;
        levelUp();
    }
});

function buttonFlash(btn) {

    btn.classList.add("flash");
    setTimeout(function() {
        btn.classList.remove("flash");
    }, 200);
}

function levelUp() {

    userSequence = [];
    levelCount++;
    document.querySelector("h2").innerText = `Level ${levelCount}`;

    let randomColor = Math.floor(Math.random() * 3);
    let color = btns[randomColor];
    let colorBtn = document.querySelector(`.${color}`);
    gameSequence.push(color);
    buttonFlash(colorBtn);
}

function reset() {

    
    startFlag = false;
    gameSequence = [];
    userSequence = [];
    levelCount = 0;

    setTimeout(function() {

        document.querySelector("body").style.backgroundColor = "white";
    }, 150);
}

function checkSequence(index) {

    if(userSequence[index] == gameSequence[index]) {
        if(userSequence.length == gameSequence.length) {

            setTimeout(levelUp, 500);
        }
    }
    else {

        if(HighScore < levelCount - 1) {

            HighScore = levelCount - 1;
        }
    
        document.querySelector("h2").innerHTML = `Game Over!<br><b>Score : ${levelCount-1}</b><br>High Score : ${HighScore}<br>Press any key to restart`;
        document.querySelector("body").style.backgroundColor = "red";
        reset();
    }
}

function buttonPress() {

    buttonFlash(this);
    let color = this.getAttribute("id");
    userSequence.push(color);

    checkSequence(userSequence.length-1);
}

let btnList = document.querySelectorAll(".btn");
for(btn of btnList) {

    btn.addEventListener("click", buttonPress);
}