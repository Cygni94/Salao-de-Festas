import React from "react";
import ReactDOM from "react-dom";
import { Provider } from "react-redux";
import { createStore, applyMiddleware } from "redux";

import reducers from "./reducers";

// no longer using routes file
// import routes from './routes';

import promise from "redux-promise";
//os componentes são importados no index.js, não no App.js
import "bootstrap";
//import "bootstrap/dist/css/bootstrap.min.css";

import CadastroClientes from "./containers/CadastroClientes";
import Header from "./components/header";

const createStoreWithMiddleware = applyMiddleware(promise)(createStore);

ReactDOM.render(
    <Provider store={createStoreWithMiddleware(reducers)}>
        <div>
            <Header />
            <CadastroClientes />
        </div>
    </Provider>,
    document.querySelector("#root")
);
