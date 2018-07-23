import React from "react";
import ReactDOM from "react-dom";
import { Provider } from "react-redux";
import { createStore, applyMiddleware } from "redux";

import reducers from "./reducers";

// no longer using routes file
// import routes from './routes';

import promise from "redux-promise";
import "bootstrap";
import App from "./App";
//import "bootstrap/dist/css/bootstrap.min.css";

const createStoreWithMiddleware = applyMiddleware(promise)(createStore);

ReactDOM.render(
    <Provider store={createStoreWithMiddleware(reducers)}>
        <App />
    </Provider>,
    document.querySelector("#root")
);
