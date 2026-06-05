import { useState } from "react";
import axios from "axios";
import "./App.css";

function App()
{
    const [output, setOutput] =
        useState("");

    const [fileName, setFileName] =
        useState("");

    const uploadFile = async (event) =>
    {
        const file =
            event.target.files[0];

        if (!file)
        {
            return;
        }

        setFileName(file.name);

        const formData =
            new FormData();

        formData.append(
            "file",
            file
        );

        try
        {
            setOutput(
                "Analyzing file..."
            );

            const response =
                await axios.post(
                    "http://localhost:8000/analyze",
                    formData,
                    {
                        headers:
                        {
                            "Content-Type":
                                "multipart/form-data"
                        }
                    }
                );

            console.log(response.data);

            setOutput(
                response.data.output ||
                "No output returned."
            );
        }
        catch(error)
        {
            console.error(error);

            if(error.response)
            {
                setOutput(
                    error.response.data.output ||
                    "Server Error"
                );
            }
            else
            {
                setOutput(
                    "Cannot connect to backend."
                );
            }
        }
    };

    return (
        <div className="container">

            <h1>Function-Level Profiling Tool</h1>
            <p className="subtitle">
              Built using Flex, Bison, AST, Symbol Table, Instrumentation and Runtime Profiling
            </p>

            <div className="card">
                <h2>
                    Project Information
                </h2>

                <table>
                    <tbody>

                        <tr>
                            <td>Lexer</td>
                            <td>Flex</td>
                        </tr>

                        <tr>
                            <td>Parser</td>
                            <td>Bison</td>
                        </tr>

                        <tr>
                            <td>AST</td>
                            <td>Implemented</td>
                        </tr>

                        <tr>
                            <td>Symbol Table</td>
                            <td>Implemented</td>
                        </tr>

                        <tr>
                            <td>Instrumentation</td>
                            <td>Implemented</td>
                        </tr>

                        <tr>
                            <td>Profiling</td>
                            <td>Implemented</td>
                        </tr>

                    </tbody>
                </table>
            </div>

            <div className="card">
                <h2>
                    Upload C Source File
                </h2>

                <input
                    type="file"
                    accept=".c"
                    onChange={uploadFile}
                />

                <br />
                <br />

                <strong>
                    Selected File:
                </strong>{" "}
                {fileName || "None"}
            </div>

            <div className="card">
                <h2>
                    Analysis Output
                </h2>

                <pre>
                    {output}
                </pre>
            </div>

        </div>
    );
}

export default App;