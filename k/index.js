import dns from 'node:dns'

import express from 'express'
import 'dotenv/config.js'
import dbconnection from './db/db.js'


dns.setDefaultResultOrder("ipv4first")

dns.setServers(["8.8.8.8","1.1.1.1"]);

const app=express()

app.get('/',(req,res)=>{
  console.log("hello")
})

const PORT=8000
app.listen(PORT,()=>{
  dbconnection()
  console.log(`server is listning on port ${process.env.PORT}`)
})