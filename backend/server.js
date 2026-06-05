const express = require("express");
const multer = require("multer");
const cors = require("cors");
const { exec } = require("child_process");

const app = express();

app.use(cors());
app.use(express.json());

const upload = multer({
    dest: "uploads/"
});

app.get("/", (req, res) => {
    res.send("Backend running");
});

app.post(
    "/analyze",
    upload.single("file"),
    (req, res) =>
    {
        if (!req.file)
        {
            return res.status(400).json({
                success: false,
                output: "No file uploaded"
            });
        }

        const filepath = req.file.path;

        /*
         * Change this path if profiler_compiler
         * is located somewhere else.
         */
        const path = require("path");

const compilerPath = path.resolve(
    __dirname,
    "../compiler/profiler_compiler"
);

const command =
    `${compilerPath} < ${filepath}`;

        console.log("\n========== REQUEST ==========");
        console.log("Uploaded File:", filepath);
        console.log("Command:", command);

        console.log("Compiler Path:", compilerPath);
        console.log("Uploaded File:", filepath);
        console.log("Command:", command);

        exec(command, (error, stdout, stderr) =>
        {
            console.log("STDOUT:\n", stdout);
            console.log("STDERR:\n", stderr);

            if (error)
            {
                console.log("ERROR:\n", error);

                return res.status(500).json({
                    success: false,
                    output:
                        stderr ||
                        error.message ||
                        "Unknown Error"
                });
            }

            res.json({
                success: true,
                output: stdout
            });
        });
    }
);

const PORT = 8000;

app.listen(PORT, () =>
{
    console.log(
        `Server running on port ${PORT}`
    );
});