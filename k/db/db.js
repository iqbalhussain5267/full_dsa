import mongoose from "mongoose";
import 'dotenv/config'
 const dbconnection=async()=>{
  try {
await mongoose.connect(process.env.M_URI)
console.log('database connected ')
  } catch (error) {
    console.log(error)
  }
 }
 export default dbconnection