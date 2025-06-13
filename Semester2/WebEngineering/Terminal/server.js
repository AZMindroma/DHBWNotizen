// server.js
const express = require('express');
const app = express();
const cors = require('cors');

app.use(cors());
app.use(express.json());

app.post('/api/command', (req, res) => {
    const { command } = req.body;
    // Process command logic here (e.g., database, custom logic)
    let response = '';
    if (command === 'help') response = 'Help me...';
    else response = `Command not found: ${command}`;
    res.json({ response });
});

app.listen(3000);