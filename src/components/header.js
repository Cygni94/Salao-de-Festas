import React from "react";
// react-router-dom replaces react-router in package.json dependencies.
// react-router 4.0.0 is a dependency of react-router-dom
import { BrowserRouter as Router, Route, Switch, Link } from "react-router-dom";
import App from "../App";
import CadastroClientes from "../containers/CadastroClientes";
import CadastroFuncionario from "../containers/CadastroFuncionario";
import Home from "../containers/Home";

const Header = () => {
    return (
        <Router>
            <div>
                <ul>
                    <li>
                        <Link to="/">Home</Link>
                    </li>
                    <li>
                        <Link to="/clientes/cadastro">Cadastrar Cliente</Link>
                    </li>
                    <li>
                        <Link to="/funcionarios/cadastro">
                            Cadastrar Funcionário
                        </Link>
                    </li>
                </ul>

                <hr />
                <Switch>
                    <Route exact path="/" component={Home} />
                    <Route
                        exact
                        path="/clientes/cadastro"
                        component={CadastroClientes}
                    />
                    <Route
                        exact
                        path="/funcionarios/cadastro"
                        component={CadastroFuncionario}
                    />
                </Switch>
            </div>
        </Router>
    );
    // <header>
    //     <nav className="navbar navbar-expand-lg navbar-light bg-light">
    //         <a className="navbar-brand" href="#">
    //             Navbar
    //         </a>
    //         <button
    //             className="navbar-toggler"
    //             type="button"
    //             data-toggle="collapse"
    //             data-target="#navbarTogglerDemo02">
    //             <span className="navbar-toggler-icon" />
    //         </button>

    //         <div
    //             className="collapse navbar-collapse"
    //             id="navbarTogglerDemo02">
    //             <ul className="navbar-nav mr-auto mt-2 mt-lg-0">
    //                 <li className="nav-item active">
    //                     <a className="nav-link" href="#">
    //                         Home <span className="sr-only">(current)</span>
    //                     </a>
    //                 </li>
    //                 <li className="nav-item">
    //                     <a className="nav-link" href="#">
    //                         Link
    //                     </a>
    //                 </li>
    //                 <li className="nav-item">
    //                     <a className="nav-link disabled" href="#">
    //                         Disabled
    //                     </a>
    //                 </li>
    //             </ul>
    //             <form className="form-inline my-2 my-lg-0">
    //                 <input
    //                     className="form-control mr-sm-2"
    //                     type="search"
    //                     placeholder="Search"
    //                 />
    //                 <button
    //                     className="btn btn-outline-success my-2 my-sm-0"
    //                     type="submit">
    //                     Search
    //                 </button>
    //             </form>
    //         </div>
    //     </nav>
    // </header>
};

export default Header;
