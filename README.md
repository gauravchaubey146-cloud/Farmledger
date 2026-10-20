# 🌾 FarmLedger — Agricultural Farm Record Management System

A simple record-keeping system for farmers to track crops, expenses, and harvests, and to see a season's profit or loss at a glance.

This repo contains **two versions** of the same project:

1. **[`/c-version`](./c-version)** — the original console-based program written in C
2. **[`index.html`](./index.html)** — a web-based version with the same logic, built with HTML, CSS, and JavaScript

---

## 📋 What it does

Both versions let you:

- **Add crops** — name, field, area, and cost. Every crop starts as `Growing`.
- **Log expenses** — general farm expenses like fertiliser or labour.
- **Record harvests** — pick a crop, enter quantity and rate, and revenue is calculated automatically (`quantity × rate`). The crop then flips to `Harvested`.
- **View a report** — total crops, harvests, and expenses, plus a full financial summary:
  - Total Revenue
  - Crop Cost
  - Other Expenses
  - Total Cost
  - **Net Profit** or **Net Loss**

---

## 💻 C Version (`/c-version`)

The original implementation — a menu-driven console application.

**Features:**
- Array-based storage for crops, expenses, and harvests (up to 20 records each)
- Menu system (`Add Crop`, `View Crops`, `Add Expense`, `View Expenses`, `Add Harvest`, `View Harvests`, `Show Report`, `Exit`)
- Prevents double-harvesting the same crop
- Calculates net profit/loss at the end of the season

**How to run it:**

```bash
cd c-version
gcc farm_management.c -o farmledger
./farmledger
```

**Note:** Data is stored only in memory — it resets every time the program exits. This limitation is what the web version was built to solve.

---

## 🌐 Web Version (`index.html`)

A browser-based rebuild of the same system, with data that actually persists.

**Features:**
- Same core logic as the C version: add crops, log expenses, record harvests, view a live report
- Data is saved automatically to the browser's `localStorage` — no login, no backend, no lost data on refresh
- Clean tabbed interface (Report / Crops / Expenses / Harvests)
- Responsive layout — works on desktop and mobile
- Delete records, with safe cascading (deleting a harvested crop also removes its linked harvest)
- Live profit/loss bar chart and summary

**Tech stack:** HTML, CSS, vanilla JavaScript — no frameworks, no dependencies, no server required.

**How to run it:**

Just open `index.html` in any browser. Or, if GitHub Pages is enabled for this repo, visit the live link:

```
https://YOUR_USERNAME.github.io/farmledger/
```

---

## 📁 Repo structure

```
farmledger/
├── index.html          # Web version — open directly or deploy via GitHub Pages
├── c-version/
│   └── farm_management.c
└── README.md
```

---

## 🧭 Why two versions?

The C version was the first pass — a straightforward console tool to model the core logic of farm record-keeping. The web version rebuilds that same logic as an actual usable app: no compiling, works on any device, and keeps your data around after you close it.

---

## 📄 License

Free to use for learning and personal/college projects.
