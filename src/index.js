import React from "react";
import ReactDOM from "react-dom";
import { Provider } from "react-redux";
import { createStore, applyMiddleware } from "redux";

// react-router-dom replaces react-router in package.json dependencies.
// react-router 4.0.0 is a dependency of react-router-dom
import { BrowserRouter as Router, Route, Switch } from "react-router-dom";

import reducers from "./reducers";

// no longer using routes file
// import routes from './routes';

import promise from "redux-promise";
//os componentes são importados no index.js, não no App.js
import "bootstrap";
import App from "./App";
import CadastroClientes from "./containers/CadastroClientes";
import Header from "./components/header";

const createStoreWithMiddleware = applyMiddleware(promise)(createStore);

ReactDOM.render(
    <Provider store={createStoreWithMiddleware(reducers)}>
        <Router>
            <App>
                <Switch>
                    <Route
                        exact
                        path="/clientes/cadastro"
                        component={CadastroClientes}
                    />
                </Switch>
            </App>
        </Router>
    </Provider>,
    document.querySelector("#root")
);
